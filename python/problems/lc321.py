from collections import deque
import sys
from typing import List, Deque




def f(i : int, j : int, nums : List[int], dp: List[List[int]] ) -> int:
    if i > j:
        return 0

    if dp[i][j] != -1:
        return dp[i][j]

    dp[i][j] = -sys.maxsize -1

    for k in range(i, j+1):
        # print(f"is is {i}, j is {j}, k is {k}")
        coin = f(i, k-1, nums, dp) + nums[i-1] * nums[k] * nums[j+1] + f(k+1, j, nums, dp)
        dp[i][j] = max(coin, dp[i][j])


    return dp[i][j]



class Solution:
    def maxCoins(self, nums: List[int]) -> int:

        l = len(nums)
        nums.insert(0, 1)
        nums.append(1)

        # dp = [[-1 for _ in range(l+2)] for _ in range(l +2)]
        # return f(1, l, nums, dp)

        dp = [[0 for _ in range(l+2)] for _ in range(l +2)]
        for i in range(l, 1 -1, -1):
            for j in range(i, l+1):
                if i > j:
                    continue
                for k in range(i, j+1):
                    coin = dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + dp[k+1][j]
                    dp[i][j] = max(coin, dp[i][j])


        return dp[1][l]







def main():
    nums = [3,1,5,8]
    # nums = [1,5]
    solution = Solution()
    print(f"ans is {solution.maxCoins(nums)}")

if __name__ == '__main__':
    main()
