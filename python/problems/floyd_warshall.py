# https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
from collections import deque
from typing import List, Deque
from icecream import ic


class Solution:
    def shortest_distance(self, matrix):
        # Code here

        n = len(matrix)

        for i in range(n):
            for j in range(n):
                if matrix[i][j] == -1:
                    matrix[i][j] = float('inf')

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if i == j:
                        continue

                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])

        for i in range(n):
            for j in range(n):
                if matrix[i][j] == float('inf'):
                    matrix[i][j] = -1


def main():
    matrix = [[0,1,43],[1,0,6],[-1,-1,0]]
    solution = Solution()
    print(f"ans is {solution.shortest_distance(matrix)}")


if __name__ == '__main__':
    main()
