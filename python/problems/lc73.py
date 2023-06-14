
from collections import deque
from typing import List, Deque




class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        rs = set()
        cs = set()

        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c] == 0:
                    rs.add(r)
                    cs.add(c)

        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if r in rs or c in cs:
                    matrix[r][c] = 0










def main():
    # matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    matrix = [[1,1,1],[1,0,1],[1,1,1]]
    solution = Solution()
    print(f"ans is {solution.setZeroes(matrix=matrix)}")
    print(matrix)

if __name__ == '__main__':
    main()
