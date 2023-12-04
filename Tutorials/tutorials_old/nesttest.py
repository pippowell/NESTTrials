import matplotlib.pyplot as plt
import nest

dir(nest)
neuron = nest.Create("iaf_psc_alpha")

print(neuron.get())

print(neuron.get("I_e"))
print(neuron.get(["V_reset", "V_th"]))

multimeter = nest.Create("multimeter")
multimeter.set(record_from=["V_m"])

spikerecorder = nest.Create("spike_recorder")

nest.Connect(multimeter, neuron)
nest.Connect(neuron, spikerecorder)

nest.Simulate(1000.0)

dmm = multimeter.get()
Vms = dmm["events"]["V_m"]
ts = dmm["events"]["times"]

plt.figure(1)
plt.plot(ts, Vms)

events = spikerecorder.get("events")
senders = events["senders"]
ts = events["times"]
plt.figure(2)
plt.plot(ts, senders, ".")
plt.show()

neuron2 = nest.Create("iaf_psc_alpha")
neuron2.set({"I_e": 370.0})

nest.Connect(multimeter, neuron2)

plt.figure(2)
Vms1 = dmm["events"]["V_m"][::2] # start at index 0: till the end: each second entry
ts1 = dmm["events"]["times"][::2]
plt.plot(ts1, Vms1)
Vms2 = dmm["events"]["V_m"][1::2] # start at index 1: till the end: each second entry
ts2 = dmm["events"]["times"][1::2]
plt.plot(ts2, Vms2)