import nest
import matplotlib
import matplotlib.pyplot as plt
import os
from pynestml.frontend.pynestml_frontend import generate_nest_compartmental_target

tests_path = os.path.realpath(os.path.dirname(__file__))
input_path = os.path.join(tests_path,"cm_default.nestml")

generate_nest_compartmental_target(
    input_path=input_path,
    target_path="/tmp/nestml-component/",
    module_name="cm_defaultmodule",
    suffix="_nestml",
    logging_level="WARNING"
)

nest.Install("cm_defaultmodule")

cm = nest.Create("cm_default_nestml")

soma_params = {
    # passive parameters
    'C_m': 89.245535,  # pF
    'g_C': 0.0,  # soma has no parent
    'g_L': 8.924572508,  # nS
    'e_L': -75.0,
    # E-type specific
    'gbar_Na': 4608.698576715,  # nS
    'e_Na': 60.,
    'gbar_K': 956.112772900,  # nS
    'e_K': -90.
}

dend_params_active = {
    # passive parameters
    'C_m': 1.929929,  # pF
    'g_C': 1.255439494,  # nS
    'g_L': 0.192992878,  # nS
    'e_L': -70.0,  # mV
    # E-type specific
    'gbar_Na': 17.203212493,  # nS
    'e_Na': 60.,  # mV
    'gbar_K': 11.887347450,  # nS
    'e_K': -90.  # mV
}

cm.compartments = [
    {"parent_idx": -1, "params": soma_params},
    {"parent_idx": 0, "params": dend_params_active},
    {"parent_idx": 1, "params": dend_params_active}
]

cm.receptors = [
    {"comp_idx": 0, "receptor_type": "AMPA_NMDA"},
    {"comp_idx": 1, "receptor_type": "AMPA_NMDA"},
    {"comp_idx": 2, "receptor_type": "AMPA_NMDA"}
]

syn_idx_soma_act = 0
syn_idx_dend_act = 1
syn_idx_dend2_act = 2

sg1 = nest.Create('spike_generator', 1, {'spike_times': [100., 1000., 1100., 1200., 1300., 1400., 1500., 1600., 1700., 1800., 1900., 2000., 5000.]})
sg2 = nest.Create('spike_generator', 1, {'spike_times': [70., 73., 76.]})
sg3 = nest.Create('spike_generator', 1, {'spike_times': [50., 70., 105.]})

nest.Connect(sg1,cm,syn_spec={
    'synapse_model': 'static_synapse',
    'weight': 5.,
    'delay': .5,
    'receptor_type': syn_idx_soma_act})

nest.Connect(sg2,cm,syn_spec={
    'synapse_model': 'static_synapse',
    'weight': 2.,
    'delay': .5,
    'receptor_type': syn_idx_dend_act})

nest.Connect(sg3,cm,syn_spec={
    'synapse_model': 'static_synapse',
    'weight': 2.,
    'delay': .5,
    'receptor_type': syn_idx_dend2_act})

mm = nest.Create('multimeter', 1, {'record_from': ['v_comp0','v_comp1','v_comp2'], 'interval': .1})

nest.Connect(mm, cm)

nest.Simulate(100.)

res = nest.GetStatus(mm, 'events')[0]

fig, axs = plt.subplots(5)

axs[0].plot(res['times'], res['v_comp0'], c='b', label='V_m_0')
axs[1].plot(res['times'], res['v_comp1'], c='r', label='V_m_1')
axs[2].plot(res['times'], res['v_comp2'], c='g', label='V_m_2')

axs[0].set_title('V_m_0')
axs[1].set_title('V_m_1')
axs[2].set_title('V_m_2')
# plt.plot(res['times'], res['v_comp2'], c='g', label='V_m_2')

axs[0].legend()
axs[1].legend()
axs[2].legend()

plt.savefig("concmech_test.png")
