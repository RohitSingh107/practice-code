# https://leetcode.com/problems/longest-consecutive-sequence/
from collections import deque
from typing import List, Deque




class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        ans = 1 
        s = set(nums)

        for i in s:
            cnt = 1
            if i - 1 in s:
                continue

            j = i
            while j + 1 in s:
                cnt += 1
                ans = max(cnt, ans)
                j += 1

        return ans











def main():
    nums = [100,4,200,1,3,2]
    nums = [0,3,7,2,5,8,4,6,0,1]
    solution = Solution()
    print(f"ans is {solution.longestConsecutive(nums)}")

if __name__ == '__main__':
    main()
