# https://leetcode.com/problems/sort-colors/description/

from collections import deque
from typing import List, Deque







class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count = [0,0,0]

        for i in nums:
            count[i] += 1

        cummulativeCount = [0,0,0]

        for i in range(3):
            if i == 0:
                cummulativeCount[i] = count[i]
                continue
            cummulativeCount[i] = cummulativeCount[i-1] + count[i]

        startingIndex = [0, 0, 0]

        for i in range(1,3):
            startingIndex[i] = cummulativeCount[i-1]

        tmp = [0] * len(nums)
        for n in nums:
            tmp[startingIndex[n]] = n
            startingIndex[n] += 1

        nums[:] = tmp









def main():
    nums = [2,0,2,1,1,0]
    solution = Solution()
    print(f"ans is {solution.sortColors(nums)}")

if __name__ == '__main__':
    main()
