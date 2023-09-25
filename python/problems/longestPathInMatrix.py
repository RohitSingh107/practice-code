# https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
from collections import deque
from typing import List, Deque


import sys
sys.setrecursionlimit(100000000)

def lip(i : int, j : int, matrix: List[List[int]], m : int, n : int, dp : List[List[int]]) -> int:

    if dp[i][j] != -1:
        return dp[i][j]

    ans = 0

    if i > 0 and matrix[i-1][j] > matrix[i][j]:
        ans = max(ans, lip(i-1, j, matrix, m, n, dp)) 

    if j > 0 and matrix[i][j-1] > matrix[i][j]:
        ans = max(ans, lip(i, j-1, matrix, m, n, dp))

    if j <= n - 2 and matrix[i][j+1] > matrix[i][j]:
        ans = max(ans, lip(i, j+1, matrix, m, n, dp))

    if i <= m - 2 and matrix[i+1][j] > matrix[i][j]:
        ans = max(ans, lip(i+1, j, matrix, m, n, dp))

    dp[i][j] = ans + 1 # 1 for this current element
    return dp[i][j]






class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:

        m = len(matrix)
        n = len(matrix[0])

        dp = [[-1 for _ in range(n)] for _ in range(m)]


        mi = 0
        mj = 0
        mp = 0

        ans = 0

        for i in range(m):
            for j in range(n):
                if dp[i][j] != -1:
                    ans = max(ans, dp[i][j])
                else:
                    ans = max(ans, lip(i,j, matrix, m,n, dp))

                if dp[i][j] > mp:
                    mp = dp[i][j]
                    mi = i
                    mj = j

     
        # print(dp)
        path = deque()
        while mi >= 0 and mj>= 0 and mi < m and mj < n:
            path.append(matrix[mi][mj])

            if mi > 0 and dp[mi][mj] - dp[mi-1][mj] == 1:
                mi -= 1
            elif mj > 0 and dp[mi][mj] - dp[mi][mj-1] == 1:
                mj -= 1
            elif mj < n - 1 and dp[mi][mj] - dp[mi][mj+1] == 1:
                mj += 1
            elif mi < m -1 and dp[mi][mj] - dp[mi+1][mj] == 1:
                mi += 1
            else:
                break
        print("path is ", path)

        return ans





def main():
    # matrix = [[9,9,4],[6,6,8],[2,1,1]]
    # matrix = [[3,4,5],[3,2,6],[2,2,1]]
    # matrix = [[1,2]]
    matrix = [[8,9,8],[7,4,3],[6,5,2]]
    solution = Solution()
    print(f"ans is {solution.longestIncreasingPath(matrix=matrix)}")

if __name__ == '__main__':
    main()
