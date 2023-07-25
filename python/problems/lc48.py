from collections import deque
from typing import List, Deque
from pprint import pprint





def pm(matrix : List[List[int]]):
    for r in matrix:
        print(r)


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        m = len(matrix)

        i = 0
        while i < m:

            for j in range(i, m):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            i += 1

        for r in matrix:
            r.reverse()
        # pm(matrix)








def main():
    # matrix = [[1,2,3],[4,5,6],[7,8,9]]
    matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    pm(matrix)
    print("----------")
    solution = Solution()
    print(f"ans is {solution.rotate(matrix=matrix)}")

if __name__ == '__main__':
    main()
