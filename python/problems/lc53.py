


from collections import deque
from typing import List, Deque

import sys





class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        ans = -sys.maxsize -1

        curr = 0
        for i in nums:
            curr += i
            if curr < 0:
                curr = 0
            ans = max(ans, curr)
            # print(f"curr is curr {curr}, i is {i}")
        if ans == 0:
            return max(nums)
        return ans






def main():
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    solution = Solution()
    print(f"ans is {solution.maxSubArray(nums=nums)}")

if __name__ == '__main__':
    main()
