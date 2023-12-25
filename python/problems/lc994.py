
from pprint import pprint
from typing import List, Deque, Tuple
from collections import deque



xd = [0, 1, 0, -1]
yd = [-1, 0, 1, 0]

# https://leetcode.com/problems/rotting-oranges/description/
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        m = len(grid)
        n = len(grid[0])

        ans = 0

        queue : Deque[Tuple[Tuple[int,int], int]] = deque()


        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append(((i,j), 0))

        while len(queue) > 0:
            ((x,y), t) = queue.popleft()

            for d in range(4):
                xi, yi = x + xd[d], y + yd[d]

                if 0 <= xi < m and 0 <= yi < n:
                    if grid[xi][yi] == 1:
                        queue.append(((xi, yi), t + 1))
                        grid[xi][yi] = 2

                        ans = max(ans, t+1)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1
        return ans








def main():
    # grid = [[2,1,1],[1,1,0],[0,1,1]]
    # grid = [[2,1,1],[0,1,1],[1,0,1]]
    grid = [[0,2]]

    solution = Solution()
    ans = solution.orangesRotting(grid)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
