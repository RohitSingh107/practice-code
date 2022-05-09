from random import randint


def merge(la,lb):
    sl = []
    while la !=[] and lb !=[]:
        if la[0] < lb[0]:
            sl.append(la.pop(0))
        else:
            sl.append(lb.pop(0))
    if la ==[]:
        sl += lb
    else:
        sl += la
    return sl





def merge_sort(us):
    if len(us) <= 1:
        return us
    else:
        md = len(us) // 2
        front =us[:md]
        back = us[md:]
        front = merge_sort(front)
        back = merge_sort(back)
    return merge(front,back)



my_list = []
for x in range(0,50,7):
    my_list.append(randint(0,50))
print(my_list)

r = merge_sort(my_list)
print(r)


def search(arl,arv):
    left = 0
    right = len(arl)-1
    while left <= right:
        mid = int((left + right)/2)
        if arl[mid] > arv:
            right = mid-1
        elif arl[mid] < arv:
            left = mid+1
        else:
            return mid
    return False
print(search(r,5))

