# https://leetcode.com/problems/n-queens/description/
from typing import List, Deque
from collections import deque
from pprint import pp, pprint
import copy


def solve(c : int, n : int, board : List[List[str]], attacks : List[List[bool]], all_boards : Deque[List[str]]):

    if c == n:
        s = list(map("".join, board))
        all_boards.append(s)
        return

 
    for r in range(n):
        upD = n - 1 + (c - r)
        dD = r + c

        if attacks[0][upD] or attacks[1][r] or attacks[2][dD]:
            continue


        board[r][c] = 'Q'
        attacks[0][upD] = True
        attacks[1][r] = True
        attacks[2][dD] = True
        solve(c+1, n, board, attacks, all_boards)
        board[r][c] = '.'
        attacks[0][upD] = False
        attacks[1][r] =False
        attacks[2][dD] =False

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]] | Deque[List[str]]:

        board = [['.' for _ in range(n)] for _ in range(n)]
        u2D = [False for _ in range(2 * n - 1)]
        hor = [False for _ in range(n)]
        d2U = [False for _ in range(2 * n - 1)]
        attacks = [u2D, hor, d2U]

        all_boards = deque()

        solve(0, n, board, attacks,all_boards)

        return all_boards






def main():
    n = 4
    solution = Solution()
    ans = solution.solveNQueens(n)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
