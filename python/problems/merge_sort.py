from collections import deque
from typing import List, Deque


len = len

def merge(left, right) -> List[int]:
    if not left:
        return right
    if not right:
        return left

    # if left[0] < right[0]:
    #     return [left[0]] + merge(left[1:], right)
    # else:
    #     return [right[0]] + merge(left, right[1:])

    tmp = deque()
    i = 0
    j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            tmp.append(left[i])
            i += 1
        else:
            tmp.append(right[j])
            j += 1

    while i < len(left):
        tmp.append(left[i])
        i += 1

    while j < len(right):
        tmp.append(right[j])
        j += 1

    return list(tmp)


def mergeSort(nums: List[int]) -> List[int]:

    if len(nums) <= 1:
        return nums

    n = len(nums) // 2

    left = mergeSort(nums[:n])
    right = mergeSort(nums[n:])

    return merge(left, right)



class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        return mergeSort(nums)



def main():
    nums = [5,2,3,1]
    solution = Solution()
    print(f"ans is {solution.sortArray(nums)}")

if __name__ == '__main__':
    main()
