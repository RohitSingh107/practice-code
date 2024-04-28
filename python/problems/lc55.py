
from pprint import pprint
from typing import List, Deque
from collections import deque




def jump(i: int, nums : List[int]) -> bool:

    if i == len(nums) -1:
        return True

    if i >= len(nums):
        return False

    ans = False

    for j in range(1, nums[i] + 1):
        ans |= jump(i + j, nums)

        if ans:
            break

    return ans


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # return jump(0, nums)

        n = len(nums)

        dp = [False] * n

        for i in  range(n - 1, -1, -1):
            if i == n - 1:
                dp[i] = True

            for j in range(1, nums[i] + 1):
                if i + j >= n:
                    break
                dp[i] |= dp[i+j]

                if dp[i]:
                    break
        return dp[0]







def main():
    # nums = [2,3,1,1,4]
    nums = [3,2,1,0,4]

    solution = Solution()
    ans = solution.canJump(nums)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
