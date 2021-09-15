import numpy as np
import matplotlib.pyplot as plt

# SHMS BCMs were used (with >5 uA beam current cut on BCM4A

#BCM currents [uA]
# before
bcm1_b  = np.array([9.087,  67.291,  59.701,  40.314,  22.745])
bcm2_b  = np.array([9.108,  67.301,  59.690,  40.378,  22.789])
bcm4a_b = np.array([8.736,  65.083,  57.692,  38.966,  21.920])
bcm4b_b = np.array([28.096, 207.455, 184.004, 124.772, 70.142])
bcm4c_b = np.array([7.835,  58.966,  52.161,  35.396,  19.808])
unser_b = np.array([0.204,  57.905,  51.169,  31.613,  14.598])

# after
bcm1_a  = np.array([9.203, 67.431, 59.835, 39.118, 22.865])
bcm2_a  = np.array([9.206, 67.351, 59.745, 39.125, 22.875])
bcm4a_a = np.array([9.208, 67.310, 59.689, 39.059, 22.802])
bcm4b_a = np.array([9.224, 67.236, 59.651, 39.169, 22.824])
bcm4c_a = np.array([9.234, 67.330, 59.598, 39.224, 22.838])
unser_a = np.array([9.428, 67.130, 60.393, 39.519, 23.822])

my_xticks = ['11799','11829','11847','11883', '11947']

x = np.array([0,1,2,3,4])
plt.xticks(x, my_xticks)

#before
plt.plot(x, bcm1_b, linestyle='', marker='o',  mfc='white', ms=5, color = 'k', label='bcm1 (before)')
plt.plot(x, bcm2_b, linestyle='', marker='s',  mfc='white', ms=5, color = 'k', label='bcm2')
plt.plot(x, bcm4a_b, linestyle='', marker='^', mfc='white', ms=5, color = 'k', label='bcm4a')
plt.plot(x, bcm4b_b, linestyle='', marker='v', mfc='white', ms=5, color = 'k', label='bcm4b')
plt.plot(x, bcm4c_b, linestyle='', marker='>', mfc='white', ms=5, color = 'k', label='bcm4c')
plt.plot(x, unser_b, linestyle='', marker='D', mfc='white', ms=5, color = 'k', label='unser')

#after
plt.plot(x, bcm1_a, linestyle='', marker='o',  mfc='white', ms=5, color = 'r', label='bcm1 (after)')
plt.plot(x, bcm2_a, linestyle='', marker='s',  mfc='white', ms=5, color = 'r', label='bcm2')
plt.plot(x, bcm4a_a, linestyle='', marker='^', mfc='white', ms=5, color = 'r', label='bcm4a')
plt.plot(x, bcm4b_a, linestyle='', marker='v', mfc='white', ms=5, color = 'r', label='bcm4b')
plt.plot(x, bcm4c_a, linestyle='', marker='>', mfc='white', ms=5, color = 'r', label='bcm4c')
plt.plot(x, unser_a, linestyle='', marker='D', mfc='white', ms=5, color = 'r', label='unser')

plt.xlabel('Run Runmber')
plt.ylabel('Beam Current [ micro-Amps ]')

plt.yscale('log')
plt.grid(True)
plt.legend()


plt.figure()



#calculate the ratio

plt.xticks(x, my_xticks)

ratio_b = bcm1_b /bcm2_b
ratio_a = bcm1_a /bcm2_a

ratio_v1b = bcm4a_b / bcm1_b
ratio_v2b = bcm4b_b / bcm1_b
ratio_v3b = bcm4c_b / bcm1_b

ratio_v1a = bcm4a_a / bcm1_a
ratio_v2a = bcm4b_a / bcm1_a
ratio_v3a = bcm4c_a / bcm1_a

plt.plot(x, ratio_v1b, linestyle='', marker='o',  mfc='white', ms=7, color = 'k', label='bcm4a/bcm1 (before)')
plt.plot(x, ratio_v2b, linestyle='', marker='^',  mfc='white', ms=7, color = 'k', label='bcm4b/bcm1 (before)')
plt.plot(x, ratio_v3b, linestyle='', marker='s',  mfc='white', ms=7, color = 'k', label='bcm4c/bcm1 (before)')

plt.plot(x, ratio_v1a, linestyle='', marker='o',  mfc='white', ms=7, color = 'r', label='bcm4a/bcm1 (after)')
plt.plot(x+0.1, ratio_v2a, linestyle='', marker='^',  mfc='white', ms=7, color = 'r', label='bcm4b/bcm1 (after)')
plt.plot(x+0.2, ratio_v3a, linestyle='', marker='s',  mfc='white', ms=7, color = 'r', label='bcm4c/bcm1 (after)')

#plt.plot(x, ratio_b, linestyle='', marker='o',  mfc='white', ms=5, color = 'k', label='bcm1/bcm2 (before)')
#plt.plot(x, ratio_a, linestyle='', marker='o',  mfc='white', ms=5, color = 'r', label='bcm1/bcm2 (after)')



plt.xlabel('Run Number')
#plt.ylabel('Ratio = BCM1 / BCM2')
plt.ylabel('Ratio = BCM4 (a,b,c) / BCM1')

plt.grid(True)
plt.legend()
plt.show()
