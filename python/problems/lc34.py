# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
from collections import deque
from typing import List, Deque





def lower_bound( nums: List[int], target: int):

    lo = 0
    hi = len(nums) - 1

    while lo <= hi:
        mid = (lo + hi) // 2

        if nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    if lo >= len(nums) or nums[lo] != target:
        return -1
    return lo

def upper_bound( nums: List[int], target: int):

    lo = 0
    hi = len(nums) - 1

    while lo <= hi:
        mid = (lo + hi) // 2
        
        if nums[mid] <= target:
            lo = mid + 1
        else:
            hi = mid - 1
    print("lo is ", lo)
    if lo == 0 or lo > len(nums) or nums[lo-1] != target:
        return -1
    return lo - 1



class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        return [lower_bound(nums, target), upper_bound(nums, target)]
        







def main():
    # nums = [5,7,7,8,8,10]
    # target = 8
    nums = [1]
    target = 1

    solution = Solution()
    print(f"ans is {solution.searchRange(nums, target)}")

    print("ub is ", upper_bound(nums, 8))
    print("lb is ", lower_bound(nums, 8))
    # print("ub is ", upper_bound([1,2,4,4,5,7,8], 4))
    # print("lb is ", lower_bound([1,2,4,4,5,7,8], 4))

if __name__ == '__main__':
    main()
