
from typing import List

def uniquePaths(m: int, n: int) -> int:
    dp = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            if i == j == 0:
                dp[i][j] = 1
                continue
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
    return dp[m-1][n-1]
    # return ways(m -1, n-1)


def ways(i, j):
    if i == j == 0:
        return 1

    if i == -1 or j == -1:
        return 0

    return ways(i -1, j) + ways(i, j-1)


m = 3
n= 7

print(uniquePaths(m,n))
