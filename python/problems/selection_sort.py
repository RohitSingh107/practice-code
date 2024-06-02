# https://leetcode.com/problems/sort-an-array/
from collections import deque
from typing import List, Deque


def selection_sort(nums: List[int]) -> List[int]:
    
    for i in range(len(nums) - 1):
        mn = i
        for j in range(i + 1 ,len(nums)):
            if nums[mn] > nums[j]:
                mn = j

        if mn != i:
            nums[mn], nums[i] = nums[i], nums[mn]

    return nums

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        return selection_sort(nums)










def main():
    nums = [5,2,3,1]
    solution = Solution()
    print(f"ans is {solution.sortArray(nums)}")

if __name__ == '__main__':
    main()
