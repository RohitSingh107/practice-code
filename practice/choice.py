from random import choice
a = []
b = []
list = []
num = int(input("please enter a even number: "))
for x in range(num):
    list.append(input('Item: '))
print(list)
def ld(group):
    for x in range(int(num/2)):
        pp = choice(list)
        group.append(pp)
        list.remove(pp)
    return group
#m = input("Please enter\n")
#n = input("Please enter a number 1-10\n")
print(ld(m),ld(n))