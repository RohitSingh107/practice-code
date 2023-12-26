from collections import deque
from typing import List, Deque


def rowSum(r: int, matrix: List[List[int]]) -> int:
    return sum(matrix[r])


def colSum(c: int, m: int, matrix: List[List[int]]) -> int:
    return sum(matrix[r][c] for r in range(m))


def f(matrix: List[List[int]], m: int, n: int, total: int):
    if total == 0:
        if not matrix:
            return None
        return matrix

    if m == 1 and n == 1:
        if matrix[0][0] == 0:
            return matrix
        return None

    if m < 0 or n < 0:
        return None

    ans = (-1, -1)

    if n > 1:
        rt = [[matrix[i][j] for j in range(0, n - 1)] for i in range(m)]
        r = f(rt, m, n - 1, total - colSum(n - 1, m, matrix))

        if r:
            x = len(r)
            y = len(r[0])
            ans = (x * y, r)
            # if ans == () or (x * y > ans[0]):
            #     ans = (x * y, r)

    d = f(matrix[:-1], m - 1, n, total - rowSum(m - 1, matrix))
    if d:
        x = len(d)
        y = len(d[0])
        if ans == () or (x * y > ans[0]):
            ans = (x * y, d)

    u = f(matrix[1:], m - 1, n, total - rowSum(0, matrix))
    if u:
        x = len(u)
        y = len(u[0])
        if ans == () or (x * y > ans[0]):
            ans = (x * y, u)

    if n > 1:
        lt = [[matrix[i][j] for j in range(1, n)] for i in range(m)]
        l = f(lt, m, n - 1, total - colSum(0, m, matrix))

        if l:
            x = len(l)
            y = len(l[0])
            if ans == () or (x * y > ans[0]):
                ans = (x * y, l)

    return [] if ans == (-1, -1) else ans[1]


class Solution:
    def sumZeroMatrix(self, a: List[List[int]]):
        m = len(a)
        n = len(a[0])
        total = 0
        for r in range(m):
            total += rowSum(r, a)

        return f(a, m, n, total)


def main():
    mat = [[1, 2, 3], [-3, -2, -1], [1, 7, 5]]
    #
    # mat = [[9, 7, 16, 5], [1, -6, -7, 3], [1, 8, 7, 9], [7, -2, 0, 10]]

    # mat = [[6, -6, -9, -5, -5], [-7, 0, -7, -6, 4], [6, -3, 3, 7, -11]]

    solution = Solution()
    print(f"ans is {solution.sumZeroMatrix(mat)}")


if __name__ == "__main__":
    main()
