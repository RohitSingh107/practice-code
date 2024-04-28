from pprint import pprint
from typing import List, Deque
from collections import deque


def travel(i: int, j: int, grid: List[List[int]]) -> int:

    if i >= len(grid) or j >= len(grid[0]) or grid[i][j] == 1:
        return 0
    if i == len(grid) - 1 and j == len(grid[0]) - 1:
        return 1

    return travel(i + 1, j, grid) + travel(i, j + 1, grid)


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

        # return travel(0, 0, obstacleGrid)
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                    continue

                if i == m - 1 and j == n - 1:
                    dp[i][j] = 1
                    continue

                dp[i][j] = dp[i + 1][j] + dp[i][j + 1]
        return dp[0][0]


def main():
    obstacleGrid = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
    # obstacleGrid = [[0, 1], [0, 0]]

    solution = Solution()
    ans = solution.uniquePathsWithObstacles(obstacleGrid)
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
