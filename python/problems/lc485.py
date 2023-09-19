from collections import deque
from typing import List, Deque



# https://leetcode.com/problems/max-consecutive-ones/
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:

        c = int(nums[0] == 1)

        ans = c

        for i in range(1,len(nums)):
            if nums[i] == 1 or nums[i] == nums[i-1] == 1:
                c += 1
                ans = max(ans, c)
            else:
                c = 0
        return ans









def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
