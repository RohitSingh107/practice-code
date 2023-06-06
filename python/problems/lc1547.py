from collections import deque
from typing import List, Deque
import sys


#
# def f(i: int, j: int, cuts: List[int], dp: List[List[int]]) -> int:
#
#     if i > j:
#         return 0
#
#     if dp[i][j] != -1:
#         return dp[i][j]
#
#     ans = sys.maxsize
#     for k in range(i, j+1):
#         cost = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts, dp) + f(k+1, j, cuts, dp)
#         ans = min(cost, ans)
#
#     dp[i][j] = ans
#
#     return dp[i][j]


class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:

        c = len(cuts)

        cuts.append(n)
        cuts.insert(0, 0)
        cuts = sorted(cuts)


        # dp = [[-1 for _ in range(l + 2)] for _ in range(l + 2)]
        inf = sys.maxsize
        dp = [[0 for _ in range(c + 2)] for _ in range(c + 2)]

        for i in range(c, 1 -1, -1):
            for j in range(i, c +1):
                if i > j:
                    continue
                dp[i][j] = inf
                for k in range(i, j+1):
                    # print(f"i is {i}, j is {j}, k is {k}")
                    cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]
                    dp[i][j] = min(dp[i][j], cost)

        return dp[1][c]








def main():
    # n = 7
    # cuts = [1,3,4,5]
    n = 9 
    cuts = [5,6,1,4,2]
    solution = Solution()
    print(f"ans is {solution.minCost(n, cuts)}")

if __name__ == '__main__':
    main()
