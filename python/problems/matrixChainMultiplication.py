from collections import deque
from typing import List, Deque
import sys




def mcm(i : int, j : int, arr : List[int], dp : List[List[int]]) -> int:

    if dp[i][j] != -1:
        return dp[i][j]

    if i == j:
        return 0

    dp[i][j] = sys.maxsize

    for k in range(i, j):
        cost = mcm(i, k, arr, dp) + mcm(k+1, j, arr, dp) + (arr[i-1] * arr[k] * arr[j]) 
        dp[i][j] = min(dp[i][j], cost)


    
    return dp[i][j]

class Solution:
    def matrixMultiplication(self, N : int, arr : List[int]) -> int:
        # # TopDown Recursion
        # dp = [[-1 for _ in range(N)] for _ in range(N)]
        # return mcm(1, N- 1, arr, dp)

        # BottomUp Tabulation
        # print(f"N is {N}")
        dp = [[0 for _ in range(N)] for _ in range(N)]
        for i in range(N-1, 0, -1):
            for j in range(i + 1, N): ## starting from 1 will also work
                if i == j:
                    continue
                dp[i][j] = sys.maxsize
                for k in range(i, j):
                    # print(f"i is {i}, j is {j}, k is {k}")
                    cost = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j])
                    dp[i][j] = min(dp[i][j], cost)
        # print(dp)
        return dp[1][N-1]



        








def main():
    solution = Solution()
    arr = [40,20,30,10,30]
    N = 5
    # arr = [10,30,5,60]
    # N = 4
    print(f"ans is {solution.matrixMultiplication(N, arr)}")

if __name__ == '__main__':
    main()
