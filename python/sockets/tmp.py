import time
for x in range(10):
    print(x, end='\r')
print()

for x in range(10):
    print("Progress {:2.1%}".format(x / 10), end="\r")
    time.sleep(1)
