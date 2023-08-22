# https://leetcode.com/problems/sort-an-array/description/

from typing import List

from collections import deque

def merge(sa1 : List[int], sa2 : List[int]) -> List[int] :
    result = deque()

    n1 = len(sa1)
    n2 = len(sa2)

    i = 0
    j = 0
    # k = 0

    while i < n1 and j < n2:
        if sa1[i] < sa2[j]:
            result.append(sa1[i])
            i += 1
        else:
            result.append(sa2[j])
            j += 1

    if i == n1:
        result.extend(sa2[j:])
    else:
        result.extend(sa1[i:])


    return list(result)

def sortArray(nums: List[int]) -> List[int]:

    if len(nums) == 1:
        return nums

    mid = len(nums) // 2

    left = nums[:mid]
    right = nums[mid:]

    right = sortArray(right) 
    left = sortArray(left)

    return merge(left, right)

arr = [12, 11, 13, 5, 6, 7]

print(sortArray(arr))

