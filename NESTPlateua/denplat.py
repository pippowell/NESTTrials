import matplotlib as mpl
import matplotlib.pyplot as plt
import nest
import numpy as np
import os

from pynestml.codegeneration.nest_code_generator_utils import NESTCodeGeneratorUtils

# assumes that the input is coming directly into the soma and if enough input is there, you must have generated an dAP and so we add that too


nestml_active_dend_model = '''
neuron iaf_psc_exp_active_dendrite:
    state:
        V_m mV = 0 mV     # membrane potential
        t_dAP ms = 0 ms   # dendritic action potential timer
        I_dAP pA = 0 pA   # dendritic action potential current magnitude

    equations:
        # alpha shaped postsynaptic current kernel
        kernel syn_kernel = (e / tau_syn) * t * exp(-t / tau_syn)
        recordable inline I_syn pA = convolve(syn_kernel, spikes_in) * pA # * pA does not mean multiplication, but rather that this value is in pA
        Vm_norm = -(V_m - E_L) / tau_m + (I_syn + I_dAP + I_e) / C_m
        Vm_plat = -(V_m - E_L) / tau_m + (I_dAP + I_e) / C_m

    parameters:
        C_m pF = 250 pF          # capacity of the membrane
        tau_m ms = 20 ms         # membrane time constant
        tau_syn ms = 10 ms       # time constant of synaptic current
        V_th mV = 25 mV          # action potential threshold
        V_reset mV = 0 mV        # reset voltage
        I_e    pA = 0 pA         # external current
        E_L    mV = 0 mV         # resting potential

        # dendritic action potential
        I_th pA = 100 pA         # current threshold for a dendritic action potential
        I_dAP_peak pA = 150 pA   # current clamp value for I_dAP during a dendritic action potential (amplitude/"height" of plateau)
        T_dAP ms = 10 ms         # time window over which the dendritic current clamp is active (duration of plateau)

    input:
        spikes_in <- spike

    output:
        spike

    update:
        # solve ODEs
        if I_syn <= I_th:
            integrate_odes(Vm_norm)
        elif I_syn > I_th:
            integrate_odes(Vm_plat)
        
        # until the timer runs out, subtract the amount of time since the last event was handled, assuming value of 1, on each step (so counting down by 1ms at a time)
        if t_dAP > 0 ms:
            t_dAP -= resolution()
            
        # when the timer runs out, set the dendritic action potential to an activity of 0 pA (no charge), and reset the timer to 0 (force to 0 in case the event handler passed a time greater than 1 at some point, and therefore ended at not 0)
        if t_dAP <= 0 ms:
            # end of dendritic action potential
            t_dAP = 0 ms
            I_dAP = 0 pA

        # if the synapse potential is higher than the threshold, fire the AP by setting the timer to the overall time variable and the amplitude/charge to the overall charge variable
        if I_syn > I_th:
            # current-threshold, emit a dendritic action potential
            t_dAP = T_dAP
            I_dAP = I_dAP_peak

        # if the voltage of the membrane of the soma is greater than the threshold, fire a somatic action potential 
        # emit somatic action potential
        if V_m > V_th:
            emit_spike()
            V_m = V_reset
'''

module_name, neuron_name = NESTCodeGeneratorUtils.generate_code_for(nestml_active_dend_model,
                                                                    logging_level="ERROR")  # try "INFO" or "DEBUG" for more debug information

nest.Install(module_name)

def evaluate_neuron(neuron_name, neuron_parms=None, t_sim=100., plot=True):
    """
    Run a simulation in NEST for the specified neuron. Inject a stepwise
    current and plot the membrane potential dynamics and action potentials generated.

    Returns the number of postsynaptic action potentials that occurred.
    """
    dt = .1   # [ms]

    nest.ResetKernel()
    try:
        nest.Install("nestml_active_dend_module")
    except :
        pass
    neuron = nest.Create(neuron_name)
    if neuron_parms:
        for k, v in neuron_parms.items():
            nest.SetStatus(neuron, k, v)

    sg = nest.Create("spike_generator", params={"spike_times": [10., 20., 30., 40., 50.]})

    multimeter = nest.Create("multimeter")
    record_from_vars = ["V_m", "I_syn", "I_dAP"]
    if "enable_I_syn" in neuron.get().keys():
        record_from_vars += ["enable_I_syn"]
    multimeter.set({"record_from": record_from_vars,
                    "interval": dt})
    sr_pre = nest.Create("spike_recorder")
    sr = nest.Create("spike_recorder")

    nest.Connect(sg, neuron, syn_spec={"weight": 50., "delay": 1.})
    nest.Connect(multimeter, neuron)
    nest.Connect(sg, sr_pre)
    nest.Connect(neuron, sr)

    nest.Simulate(t_sim)

    mm = nest.GetStatus(multimeter)[0]
    timevec = mm.get("events")["times"]
    I_syn_ts = mm.get("events")["I_syn"]
    I_dAP_ts = mm.get("events")["I_dAP"]
    ts_somatic_curr = I_syn_ts + I_dAP_ts
    if "enable_I_syn" in mm.get("events").keys():
        enable_I_syn = mm.get("events")["enable_I_syn"]
        ts_somatic_curr = enable_I_syn * I_syn_ts + I_dAP_ts

    ts_pre_sp = nest.GetStatus(sr_pre, keys='events')[0]['times']
    ts_sp = nest.GetStatus(sr, keys='events')[0]['times']
    n_post_spikes = len(ts_sp)

    if plot:
        n_subplots = 3
        n_ticks = 4
        if "enable_I_syn" in mm.get("events").keys():
            n_subplots += 1
        fig, ax = plt.subplots(n_subplots, 1, dpi=100)
        ax[0].scatter(ts_pre_sp, np.zeros_like(ts_pre_sp), marker="d", c="orange", alpha=.8, zorder=99)
        ax[0].plot(timevec, I_syn_ts, label=r"I_syn")
        ax[0].set_ylabel("I_syn [pA]")
        ax[0].set_ylim(0, np.round(1.1*np.amax(I_syn_ts)/50)*50)
        ax[0].yaxis.set_major_locator(mpl.ticker.LinearLocator(n_ticks))
        twin_ax = ax[0].twinx()
        twin_ax.plot(timevec, I_dAP_ts, linestyle="--", label=r"I_dAP")
        twin_ax.set_ylabel("I_dAP [pA]")
        twin_ax.set_ylim(0, max(3, np.round(1.1*np.amax(I_dAP_ts)/50)*50))
        twin_ax.legend(loc="upper right")
        twin_ax.yaxis.set_major_locator(mpl.ticker.LinearLocator(n_ticks))
        ax[-2].plot(timevec, ts_somatic_curr, label="total somatic\ncurrent")
        ax[-2].set_ylabel("[pA]")
        if "enable_I_syn" in mm.get("events").keys():
            ax[1].plot(timevec, enable_I_syn, label="enable_I_syn")
            ax[1].set_ylim([-.05, 1.05])
            ax[1].set_yticks([0, 1])
        ax[-1].plot(timevec, mm.get("events")["V_m"], label="V_m")
        ax[-1].scatter(ts_sp, np.zeros_like(ts_sp), marker="d", c="olivedrab", alpha=.8, zorder=99)
        ax[-1].set_ylabel("V_m [mV]")
        ax[-1].set_xlabel("Time [ms]")
        for _ax in set(ax) | set([twin_ax]):
            _ax.grid()
            if not _ax == twin_ax: _ax.legend(loc="upper left")
            if not _ax == ax[-1]: _ax.set_xticklabels([])
            for _loc in ['top', 'right', 'bottom', 'left']: _ax.spines[_loc].set_visible(False) # hide axis outline
        for o in fig.findobj(): o.set_clip_on(False)  # disable clipping
        fig.show()

        return n_post_spikes

n_post_sp = evaluate_neuron(neuron_name,neuron_parms={"I_th": 100., "I_dAP_peak": 400.})

assert n_post_sp == 2   # check for correctness of the result