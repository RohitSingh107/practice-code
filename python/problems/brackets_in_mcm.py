# https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
from collections import deque
from typing import List, Deque

import sys
from pprint import pprint




def mcm(i : int, j : int, arr : List[int]) -> int:

    if j == i:
        return 0


    ans = sys.maxsize

    for k in range(i, j):
        calculations = (arr[i-1] * arr[k] * arr[j]) + mcm(i, k, arr) + mcm(k+1, j, arr) # m x n -> n represent matrix
        ans = min(ans, calculations)


    return ans



class Solution:
    def matrixMultiplication(self, N, arr):
        # code here
        # return mcm(1, N-1, arr)

        dp = [[sys.maxsize for _ in range(N)] for _ in range(N)]

        for i in range(N -1, 0, -1):
            for j in range(N):
                if i == j:
                    dp[i][j] = 0
                else:
                    for k in range(i,j):
                        dp[i][j] = min(dp[i][j], arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j])

        pprint(dp)

        return dp[1][N-1]







def main():
    # arr = [40, 20, 30, 10, 30]
    arr =[10, 30, 5, 60]

    solution = Solution()
    print(f"ans is {solution.matrixMultiplication(len(arr), arr)}")

if __name__ == '__main__':
    main()
