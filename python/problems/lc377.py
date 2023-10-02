# https://leetcode.com/problems/combination-sum-iv/submissions/
from pprint import pprint
from typing import List, Deque
from collections import deque


def combs(target : int, nums : List[int]) -> int:

    if target == 0:
        return 1
 
    ans = 0

    for i in nums:
        if i > target:
            break
        ans += combs(target - i, nums)

    return ans


class Solution:

    ans = 0

    def combs(self, target : int, nums : List[int]):
        # print(f"target is {target} ")

        if target == 0:
            self.ans += 1
            return
        for i in nums:
            if i > target:
                break
            self.combs(target - i, nums)

    def combinationSum4(self, nums: List[int], target: int) -> int:

        nums.sort()
        # return combs(target, nums)

        dp = [0] * (target + 1)

        for t in range(0, target+1):
            if t == 0:
                dp[t] = 1
                continue
            for i in nums:
                if i > t:
                    break
                dp[t] += dp[t - i]
        return dp[target]














def main():
    # nums = [1,2,3]
    # target = 4
    nums = [4,2,1]
    target = 32
    solution = Solution()
    ans = solution.combinationSum4(nums, target)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
