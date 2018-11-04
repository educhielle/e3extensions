import numpy as np
import matplotlib.pyplot as plt
from matplotlib import *
from matplotlib.ticker import MaxNLocator
from matplotlib.font_manager import FontProperties

plt.rcParams.update({'font.size': 12})

# ----------------------------- #
#             DATA              #
# ----------------------------- #

# time in seconds
# each line is a benchmark (BS, FAC, FIB, IS, MM, SoE)
# each column is a configuration (x86+gfun, x86+hwall) normalized by x86-only

hwop = np.matrix(' \
    7.86E-03	7.88E-03 ;\
    8.52E-03	8.54E-03 ;\
    9.67E-03	9.69E-03 ;\
    8.72E-03	8.74E-03 ;\
    7.98E-03	8.00E-03 ;\
    8.47E-03	8.50E-03 \
')

# uart = np.matrix(' \
#     1.61E-01	1.04E+00 ;\
#     1.75E-01	1.13E+00 ;\
#     1.99E-01	1.27E+00 ;\
#     1.79E-01	1.15E+00 ;\
#     1.64E-01	1.02E+00 ;\
#     1.74E-01	1.06E+00 \
# ')

x86 = np.matrix(' \
    5.97E-01	3.62E-03 ;\
    6.41E-01	3.93E-03 ;\
    7.23E-01	4.45E-03 ;\
    6.57E-01	4.02E-03 ;\
    6.02E-01	3.70E-03 ;\
    6.40E-01	3.93E-03 \
')

# ----------------------------- #
#       ORGANIZING DATA         #

N_LIN = 6
N_COL = 2
# ----------------------------- #

x86time  = [[0 for j in range(N_LIN)] for i in range(N_COL)]
# uarttime = [[0 for j in range(N_LIN)] for i in range(N_COL)]
hwoptime = [[0 for j in range(N_LIN)] for i in range(N_COL)]
for i in range(N_LIN):
    for j in range(N_COL):
        # if j == 1:
            # x86time[j][i] = x86[i,j]
            # hwoptime[j][i] = hwop[i,j] + x86time[j][i] #uarttime[j][i]
        # uarttime[j][i] = uart[i,j] + x86time[j][i]
        # else:
        hwoptime[j][i] = hwop[i,j]
        x86time[j][i] = x86[i,j] + hwoptime[j][i]

ind = np.arange(N_LIN)
width = 0.3       # the width of the bars: can also be len(x) sequence
offset = np.arange(-0.1, (N_COL+2)*width, width)
x = range(0, N_COL)
xaxis = [0, 'BS', 'FAC', 'FIB', 'IS', 'MM', 'SoE']
legend1 = ['CoPHEE', 'UART', 'x86']
legend2 = ['trust', 'all']
xoff = 0.5
figsize_x = 5.8 #12
figsize_y = 3.5 #5.5

colors_p0 = ('#FFFFFF', '#FFFFFF')
colors_p1 = ('#6F443A', '#6F443A')
colors_p2 = ('#9CE8B7', '#9CE8B7')
colors_p3 = ('#5682FF', '#5682FF')
edgecolor_p1 = ('#000000', '#000000')
edgecolor_p2 = ('#000000', '#000000')
edgecolor_p3 = ('#000000', '#000000')
hatch_p0 = (' ', '//', '\\', '\\\\//')
hatch_p1 = (' ', '//', '\\', '\\\\//')
hatch_p2 = (' ', '//', '\\', '\\\\//')
hatch_p3 = (' ', '//', '\\', '\\\\//')


# x86 x GFUN x CoPHEE
fig, ax = plt.subplots(1, 1, figsize=(figsize_x,figsize_y))
fontP = FontProperties()
fontP.set_size('small')

p1 = [0 for i in range(N_COL)]
# p2 = [0 for i in range(N_COL)]
p0 = [0 for i in range(N_COL)]
p3 = [0 for i in range(N_COL)]
for i in range(N_COL):
    p0[i] = ax.bar(ind + offset[i], hwoptime[i], width, color=colors_p0[i], hatch=hatch_p0[i])
    if i == 0:
        p3[i] = ax.bar(ind + offset[i],  x86time[i], width, color=colors_p3[i], edgecolor=edgecolor_p3[i], hatch=hatch_p3[i], label=legend1[2])
        p1[i] = ax.bar(ind + offset[i], hwoptime[i], width, color=colors_p1[i], edgecolor=edgecolor_p1[i], hatch=hatch_p1[i], label=legend1[0])
        # p2[i] = ax.bar(ind + offset[i], uarttime[i], width, color=colors_p2[i], edgecolor=edgecolor_p2[i], hatch=hatch_p2[i], label=legend1[1])
    else:
        p3[i] = ax.bar(ind + offset[i],  x86time[i], width, color=colors_p3[i], edgecolor=edgecolor_p3[i], hatch=hatch_p3[i])
        p1[i] = ax.bar(ind + offset[i], hwoptime[i], width, color=colors_p1[i], edgecolor=edgecolor_p1[i], hatch=hatch_p1[i])
        # p2[i] = ax.bar(ind + offset[i], uarttime[i], width, color=colors_p2[i], edgecolor=edgecolor_p2[i], hatch=hatch_p2[i])

ax.set_yscale('log')
ax.set_ylabel('normalized performance')
plt.ylim(5*10**(-3), 1.00)

ax.set_xticklabels(xaxis, rotation=25)
ax.xaxis.set_major_locator(MaxNLocator(integer=True))
plt.xlim(-xoff, (N_LIN))

l1 = ax.legend(p0, legend2, loc='upper center', bbox_to_anchor=(0.82, 1.08), ncol=2, fancybox=True, shadow=True, prop=fontP)
ax.legend(loc=2, ncol=2, prop=fontP,  bbox_to_anchor=(-0.01, 1.08)) #, title="key size")
ax.add_artist(l1)

for tick in ax.xaxis.get_majorticklabels():
    tick.set_horizontalalignment("left")

plt.tight_layout(h_pad=0.9)
ax.yaxis.grid()
fig.savefig('performance.png')
