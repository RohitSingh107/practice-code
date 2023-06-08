from collections import deque
from typing import List, Deque





class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:

        row = len(matrix)
        col = len(matrix[0])

        
        ans = 0
        dp = [[0 for _ in range(col)] for _ in range(row)]

        for c in range(col):
            dp[0][c] = matrix[0][c]
            ans += matrix[0][c]


        for r in range(row):
            dp[r][0] = matrix[r][0]
            ans += matrix[r][0]

        if matrix[0][0]:
            ans -= 1

        # print(ans)
        for r in range(1, row):
            for c in range(1, col):
                if matrix[r][c]:
                    dp[r][c] = min(dp[r][c-1], dp[r-1][c-1], dp[r-1][c]) + 1
                else:
                    dp[r][c] = 0
                ans += dp[r][c]

        for r in dp:
            print(r)
        return ans










def main():
    # matrix = [[0,1,1,1],[1,1,1,1],[0,1,1,1]]
    # matrix = [[1,1,1,1],[1,1,1,1],[1,1,1,1]]
    matrix = [[1,0,1],[1,1,0],[1,1,0]]
    solution = Solution()
    print(f"ans is {solution.countSquares(matrix)}")


if __name__ == '__main__':
    main()
