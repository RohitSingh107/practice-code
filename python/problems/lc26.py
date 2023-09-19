# https://leetcode.com/problems/remove-duplicates-from-sorted-array/
from collections import deque
from typing import List, Deque







class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        i = 1
        while i < len(nums):
            if nums[i] == nums[i-1]:
                del nums[i]
            else:
                i += 1
        return len(nums)
  




def main():
    nums = [0,0,1,1,1,2,2,3,3,4]
    solution = Solution()
    print(f"ans is {solution.removeDuplicates(nums=nums)}")

if __name__ == '__main__':
    main()
