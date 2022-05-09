list = [1,5,1,9,5,1,8,1,3,7,6]
for j in range (0,11):
    check_swap = False
    for x in range(0,10):
        if list[x] > list[x+1]:
            swap = list[x]
            list[x] = list[x+1]
            list[x+1] = swap
            check_swap = True
    if check_swap == False:
            break

print(j,list)