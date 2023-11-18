# https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
from collections import deque
from typing import List, Deque

import sys

# 1, 2, 4, 4, 5, 7, 8


def upper_bound(row, n):
    lo = 0
    hi = len(row) - 1

    while lo <= hi:
        mid = (lo + hi) // 2
        if row[mid] <= n:
            lo = mid + 1
        else:
            hi = mid - 1
    return lo


def lesserAndEqual(n, matrix):
    ans = 0
    for row in matrix:
        ans += upper_bound(row, n)
    return ans


class Solution:
    def median(self, matrix, R, C):
        # code here

        lo = sys.maxsize
        hi = -1 * lo

        for i in range(R):
            lo = min(lo, matrix[i][0])

        for i in range(R):
            hi = max(hi, matrix[i][C-1])

        med = (R * C) // 2

        while lo <= hi:
            mid = (lo + hi) // 2
            if lesserAndEqual(mid, matrix) <= med:
                lo = mid + 1
            else:
                hi = mid - 1
        return lo


def main():
    # R = 3
    # C = 3
    # M = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
    # R = 3
    # C = 1
    # M = [[1], [2], [3]]

    R = 3
    C = 3
    M = [[14,33,46],[4,16,46],[23,44,47]]

    solution = Solution()
    print(f"ans is {solution.median(M, R, C)}")
    # print("ub is ", upper_bound([1,2,4,4,5,7,8], 9))
    # print("ub is ", upper_bound([3,6,9], 3))


if __name__ == "__main__":
    main()
