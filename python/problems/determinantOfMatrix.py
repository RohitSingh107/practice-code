from pprint import pprint
from typing import List, Deque
from collections import deque


class Solution:
    # Function for finding determinant of matrix.
    def determinantOfMatrix(self, matrix: List[List[int]], n) -> int:
        # code here

        # print("matrix is ", matrix, "n is ", n)

        if n == 1:
            return matrix[0][0]

        ans = 0
        sign = 1

        for c in range(n):
            left_matrix = [
                [matrix[i][j] for j in range(n) if j != c] for i in range(1, n)
            ]
            ans += (sign * matrix[0][c]) * self.determinantOfMatrix(left_matrix, n - 1)
            sign *= -1
        return ans


def main():
    # n = 3
    # matrix = [[1, 2, 3],
    #           [4, 5, 6],
    #           [7, 10, 9]]

    n = 4
    matrix = [[1, 0, 2, -1], [3, 0, 0, 5], [2, 1, 4, -3], [1, 0, 5, 0]]

    solution = Solution()
    ans = solution.determinantOfMatrix(matrix, n)
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
