

from typing import List

def f1(arr):

    index = 0

    for i in range(len(arr)):
        if i == 0 or arr[i] != arr[i-1]:
            arr[index] = arr[i]
            index += 1

    del arr[index:]

    return arr

# def f2(arr : List[int]):
#
#
#     for i, e in enumerate(arr):
#         if arr[i] == arr[i-1]:
#             arr.remove(e)
#
#     return arr

arr = [1,1,1,1,1,4,2,2,5,6,6,7,7,9,8,8]

print(f1(arr))
# print(f2(arr))
