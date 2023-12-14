from collections import deque
from typing import List, Deque, Tuple

import sys


dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]


def solve(
    matrix: List[List[int]], initial: Tuple[int, int], final: Tuple[int, int]
) -> int:
    if initial == final:
        return 0

    m = len(matrix)
    n = len(matrix[0])

    ans = sys.maxsize

    mx = -sys.maxsize

    for i in range(8):
        x = initial[0] + dx[i]
        y = initial[1] + dy[i]
        if m > x >= 0 and n > y >= 0:
            mx = max(mx, matrix[x][y])

    for i in range(8):
        x = initial[0] + dx[i]
        y = initial[1] + dy[i]
        if m > x >= 0 and n > y >= 0:
            # if matrix[x][y] >= matrix[initial[0]][initial[1]] and (
            if (x,y) != initial and (
                (abs(x - final[0]) <= abs(initial[0] - final[0]))
                and abs(y - final[1]) <= abs(initial[1] - final[1])
            ):
                toAdd = 0 if mx == matrix[x][y] else mx + 1 - matrix[x][y]
                matrix[x][y] += toAdd
                new = solve(matrix, (x, y), final) + toAdd
                matrix[x][y] -= toAdd
                ans = min(ans, new)
                # print("ans is ", ans)
    return ans


def main():
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

    # initial = (0, 2)
    # final = (2, 0)

    # initial = (1, 1)
    # final = (3, 0)

    initial = (3, 3)
    final = (0, 0)

    print(f"ans is {solve(matrix, initial, final)}")


if __name__ == "__main__":
    main()
