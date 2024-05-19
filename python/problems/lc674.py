# https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
from pprint import pprint
from typing import List, Deque
from collections import deque


class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:

        ans = -float('inf')

        currMax = 0
        prev = -float('inf')

        for n in nums:
            if n > prev:
                currMax += 1
            else:
                currMax = 1
            prev = n

            ans = max(ans, currMax)

        return int(ans)






def main():
    # nums = [1,3,5,4,7]
    nums = [2,2,2,2,2]
    solution = Solution()
    ans = solution.findLengthOfLCIS(nums)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
