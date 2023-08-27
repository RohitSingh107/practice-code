# https://www.codingninjas.com/studio/problems/count-inversions_615

from typing import List
from collections import deque

def mergeSort(arr, start, end) -> int:
    # print(f"start is {start}, end is {end}")
    cnt = 0
    if end - start <= 1:
        return cnt
    mid = (start + end )// 2
    # print(f"start is {start}, mid is {mid}, end is {end}")
    cnt = 0

    left = mergeSort(arr, start, mid)
    # print(f"left is {left}")
    right = mergeSort(arr, mid, end)
    # print(f"right is {right}")

    return left + right + merge(arr, start, mid, end)



def merge(arr, start, mid, end) -> int:

    # print(f"start is {start}, mid is {mid}, end is {end}")
    i = start
    j = mid
    c = 0
    tmp = deque()
    while i < mid and j < end:
        if arr[i] > arr[j]:
            c += mid - i
            tmp.append(arr[j])
            j += 1
        else:
            tmp.append(arr[i])
            i += 1

    tmp.extend(arr[i:mid])
    tmp.extend(arr[j:end])

    arr[start:end] = list(tmp)

    return c


def getInversions(arr : List[int], n) -> int:
	# Write your code here.
    return mergeSort(arr, 0, len(arr))

# arr = [2,5,1,3,4]
arr = [3,2,1]
print(getInversions(arr, len(arr)))

