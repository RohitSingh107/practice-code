# https://leetcode.com/problems/sliding-window-maximum/description/
from pprint import pprint
from typing import List, Deque
from collections import deque




class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        start = 0
        end = k

        ans : Deque[int]  = deque()

        for i in range(len(nums) - k + 1):
            start = i
            end = i + k
            ans.append(max(nums[start:end]))

        return list(ans)







def main():
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    solution = Solution()
    ans = solution.maxSlidingWindow(nums,k)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
