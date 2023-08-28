# https://leetcode.com/problems/reverse-pairs/

from typing import List
from collections import deque

def reversePairs(nums: List[int]) -> int:

    ans = mergeSort(nums, 0, len(nums))
    print(nums)
    return ans


def mergeSort(nums : List[int], i : int, j: int) -> int:

    if j - i <= 1:
        return 0

    mid = (i + j) // 2
    # print(f"i is {i}, mid is {mid}, j is {j}")


    left = mergeSort(nums, i, mid)
    right = mergeSort(nums, mid, j)
    

    return left + right + merge(nums, i, mid, j)

def merge(nums : List[int], start : int, mid : int, end : int) -> int:
    # print(f"start is {start}, mid is {mid}, end is {end}")

    ans = 0

    # i = start
    # r = mid
    # while i < mid:
    #     while r < end and nums[i] > 2 * nums[r]:
    #         r +=1
    #     ans += r - mid
    #     i += 1
    r = mid
    for i in range(start, mid):
        while r < end and nums[i] > 2 * nums[r]:
            r += 1
        ans += (r - mid)
    
    i = start
    j = mid
    tmp = deque()
    while i < mid and j < end:
        if nums[i] <= nums[j]:
            tmp.append(nums[i])
            i += 1
        else:
            tmp.append(nums[j])
            j += 1

    tmp.extend(nums[i:mid])
    tmp.extend(nums[j:end])

    nums[start:end] = list(tmp)[:]
    
    # print(f"start is {nums[start]}, mid is {nums[mid]}, end is {nums[end-1]}, ans is {ans}")

    return ans

# nums = [1,3,2,3,1]
# nums = [2,4,3,5,1]
# nums = [6,13,21,25,1,2,3,4,4,5,6,9,11,13]
nums = [40,25,19,12,9,6,2]
print(reversePairs(nums))
