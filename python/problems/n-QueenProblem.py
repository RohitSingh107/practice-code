# https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
from pprint import pprint
from typing import List, Deque
from collections import deque


def isSafe(i : int, j : int, n : int, attacks : List[List[bool]]) -> bool:

    if attacks[0][i+j]:
        return False
    if attacks[1][i]:
        return False
    if attacks[2][n - 1 - i + j]:
        return False

    return True

def f(j : int, n : int, positions : List[int], attacks : List[List[bool]], all_positions : Deque[List[int]]):
    
    for i in range(n):
        if isSafe(i, j, n, attacks):
            attacks[0][i+j] = True
            attacks[1][i] = True
            attacks[2][n - 1 - i + j] = True
            positions[j] = i + 1
            if j == n - 1:
                all_positions.append(positions.copy())
            else:
                f(j+1, n, positions, attacks, all_positions)
            positions[j] = -1
            attacks[0][i+j] = False
            attacks[1][i] = False
            attacks[2][n - 1 - i + j] = False


class Solution:
    def nQueen(self, n):
        # code here

        u2D = [False] * (2 * n - 1)
        hor = [False] * n
        d2U = [False] * (2 * n - 1)
        attacks = [u2D, hor, d2U]

        positions = [-1] * n
        all_positions = deque()

        f(0, n, positions, attacks, all_positions)

        return all_positions










def main():
    n = 4
    solution = Solution()
    ans = solution.nQueen(n)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
