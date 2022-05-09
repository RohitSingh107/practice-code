from random import randint
list = []
for x in range(0,20):
    list.append(randint(0,9))
print(list)
import matplotlib.pyplot as plot
plot.bar(range(20),list, align='center', alpha=0.5)
plot.xticks(range(20))
plot.ylabel('frequency')
plot.title('graph')
plot.show()
plot.savefig(fname='chart.png')