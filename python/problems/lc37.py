# https://leetcode.com/problems/sudoku-solver/
from typing import List, Deque
from collections import deque
from pprint import pp, pprint
import sys


def check_row(r: int, board: List[List[str]]) -> bool:
    # pprint(board)
    check = [False] * 10
    for c in board[r]:
        check[int(c)] = True

    for c in range(1, 10):
        if not check[c]:
            return False
    return True


def check_col(c: int, board: List[List[str]]) -> bool:
    check = [False] * 10

    for r in range(9):
        check[int(board[r][c])] = True

    for r in range(1, 10):
        if not check[r]:
            return False
    return True


def check_grid(c: int, board: List[List[str]]) -> bool:
    # print("c is ", c)
    # pprint(board)
    # print()
    # print()
    # print()
    # print()
    check = [False] * 10

    for i in range(c - 2, c + 1):
        for j in range(c - 2, c + 1):
            check[int(board[i][j])] = True

    for i in range(1, 10):
        if not check[i]:
            return False
    return True


def check(r: int, c: int, num: str, board: List[List[str]]):
    for i in range(9):
        if board[r][i] == num:
            return False
        if board[i][c] == num:
            return False
        if board[3 * (r // 3) + (i // 3)][3 * (c // 3) + (i % 3)] == num:
            return False
    return True


def solve(
    i: int, j: int, board: List[List[str]], current_row: List[bool]
) -> List[List[str]] | None:
    # if i == 1 and j >= 1:
    #     print(f"{i=}, {j=}")
    #     pprint(board[1])
    # if board[0] == ["5","1","9","7","4","8","6","3","2"]:
    #     pprint(board[1])
    #     print("here11111111111111")
    # if board[1][:8] == ["7","8","3","6","5","2","4","1"]:
    #     print("here111111111")
    # if i == 1 and j == 8 and board[i][j-7] == "7" and board[i][j-6] == "2" and board[i][j-5] == "1" and board[i][j-4] == "9" and board[i][j-3] == "5" and board[i][j-2] == "3" and board[i][j-1] == "4":
    #     print("againn")
    # if board[0] == ["5", "3", "4", "6", "7", "8", "9", "1", "2"]:
    #     print("here00000")
    # if board[1] == ["6", "7", "2", "1", "9", "5", "3", "4", "8"]:
    #     print("here11111")

    if i == 8 and j > 0:
        if not check_col(j - 1, board):
            # print("n1")
            return None

    if i == (j - 1) and (i + 1) % 3 == 0:
        if not check_grid(i, board):
            # print("n2")
            return None
    # pprint(board)
    # print()
    # print()
    # print()
    # print(f"{i=}, {j=}")

    # if board[1] == ['6', '2', '3', '1', '9', '5', '4', '7', '8']:
    #     print("here1111111111111")

    if board[i][j] == ".":
        if j == 8:
            if i == 8:
                # print("here1")
                for k in range(1, 9 + 1):
                    # if board[1] == ['6', '2', '3', '1', '9', '5', '4', '7', '8']:
                    #     print(f"here1 {i=}, {j=}, {k=}")

                    if not current_row[k] and check(i, j, str(k), board):
                        current_row[k] = True
                        board[i][j] = str(k)
                        if (
                            check_col(j, board)
                            and check_row(i, board)
                            and check_grid(8, board)
                        ):
                            # pprint(board)
                            return board

                        current_row[k] = False
                        board[i][j] = "."
            else:
                # if j == 8:
                #     print("heeeeeeeeeeeeeeeeeeeeeeeeee")

                for k in range(1, 9 + 1):
                    # if board[1][:8] == ["7","8","3","6","5","2","4","1"]:
                    #     print(f"here1 {i=}, {j=}, {k=}, {current_row=}")
                    # print("here111111111")
                    # if i == 1 and j == 8:
                    #     print(f"here1 {i=}, {j=}, {k=}, {current_row=}")
                    # if i == 1 and j == 8 and board[i][j-7] == "7" and board[i][j-6] == "2" and board[i][j-5] == "1" and board[i][j-4] == "9" and board[i][j-3] == "5" and board[i][j-2] == "3" and board[i][j-1] == "4":
                    #     # print("agannninn")
                    #     print(f"here1 {i=}, {j=}, {k=}, {current_row=}")
                    # if board[1] == ['6', '2', '3', '1', '9', '5', '4', '7', '8']:
                    #     print(f"here1 {i=}, {j=}, {k=}")
                    if not current_row[k] and check(i, j, str(k), board):
                        current_row[k] = True
                        board[i][j] = str(k)
                        #
                        # if board[0][2] == "4":
                        # pprint(board[0])
                        # print()
                        #     print()
                        #     print()
                        #     print()
                        # print(f"here1 {i=}, {j=}, {k=}")
                        # if i == 0:
                        # print("here0")
                        org_current_row = current_row
                        if check_row(i, board):
                            # print(f"here2 {i=}, {j=}, {k=}")
                            current_row = [False] * 10
                            # if i == 1:
                            #     print(f"here1, {board[1]}")
                            ans = solve(i + 1, 0, board, current_row)
                            if ans is not None:
                                return ans
                            # if i == 1:
                            #     print("here2")
                            # print(f"here3 {i=}, {j=}, {k=}")
                        # print(f"here3 {i=}, {j=}, {k=}")
                        current_row = org_current_row
                        current_row[k] = False
                        board[i][j] = "."

        else:
            for k in range(1, 9 + 1):
                # if board[0][2] == "4":
                # print("here-------------")

                # if board[1] == ['6', '2', '3', '1', '9', '5', '4', '7', '8']:
                # if i == 1 and j == 7 and board[i][j-6] == "7" and board[i][j-5] == "2" and board[i][j-4] == "1" and board[i][j-3] == "9" and board[i][j-2] == "5" and board[i][j-1] == "3":
                #     print(f"here1 {i=}, {j=}, {k=}, {current_row=}")
                # print("agannninn")
                # if i == 1 and j == 7:
                #     print("here")
                if not current_row[k] and check(i, j, str(k), board):
                    # if i == 1 and j == 2:
                    #     print(f"{i=}, {j=}, {k=}")
                    board[i][j] = str(k)
                    current_row[k] = True
                    ans = solve(i, j + 1, board, current_row)
                    if ans is not None:
                        return ans
                    current_row[k] = False
                    board[i][j] = "."
    else:
        if j == 8:
            if i == 8:
                # print("here2")
                current_row[int(board[i][j])] = True
                if check_row(i, board) and check_col(j, board):
                    # print("here3")
                    # pprint(board)
                    return board
                current_row[int(board[i][j])] = False

            else:
                current_row[int(board[i][j])] = True
                org_current_row = current_row

                if check_row(i, board):
                    current_row = [False] * 10
                    # if i == 1:
                    # print("here3")
                    ans = solve(i + 1, 0, board, current_row)
                    if ans is not None:
                        # print("r3")
                        return ans
                    # if i == 1:
                    # print("here4")

                current_row = org_current_row
                current_row[int(board[i][j])] = False
        else:
            current_row[int(board[i][j])] = True
            ans = solve(i, j + 1, board, current_row)
            if ans is not None:
                return ans
            current_row[int(board[i][j])] = False


def solve2(board):
    for r in range(9):
        for c in range(9):
            if board[r][c] == ".":
                for i in range(1, 9 + 1):
                    if check(r, c, str(i), board):
                        board[r][c] = str(i)
                        if solve2(board):
                            return True
                        board[r][c] = '.'
                return False
    return True


class Solution:
    def solveSudoku(self, board: List[List[str]]):
        """
        Do not return anything, modify board in-place instead.
        """

        # current_row = [False] * 10
        # return solve(0, 0, board, current_row)
        ans = solve2(board)
        pprint(board)
        print(ans)


def main():
    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    # board = [
    #     [".", ".", "9", "7", "4", "8", ".", ".", "."],
    #     ["7", ".", ".", ".", ".", ".", ".", ".", "."],
    #     [".", "2", ".", "1", ".", "9", ".", ".", "."],
    #     [".", ".", "7", ".", ".", ".", "2", "4", "."],
    #     [".", "6", "4", ".", "1", ".", "5", "9", "."],
    #     [".", "9", "8", ".", ".", ".", "3", ".", "."],
    #     [".", ".", ".", "8", ".", "3", ".", "2", "."],
    #     [".", ".", ".", ".", ".", ".", ".", ".", "6"],
    #     [".", ".", ".", "2", "7", "5", "9", ".", "."],
    # ]
    solution = Solution()
    ans = solution.solveSudoku(board)
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
