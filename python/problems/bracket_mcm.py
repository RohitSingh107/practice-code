# https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
from collections import deque
from typing import List, Deque


import sys

name = "A"

res = deque()

def printParenthesis(i, j, n, bracket):
    global name
    global res

    if i == j:
        # print(name, end="")
        res.append(name)
        name = chr(ord(name) + 1)
        return

    # print("(", end="")
    res.append('(')

    printParenthesis(i, bracket[i][j], n, bracket)

    printParenthesis(bracket[i][j] + 1, j, n, bracket)
    # print(")", end="")
    res.append(')')


class Solution:
    def matrixMultiplication(self, N, arr):
        # code here

        dp = [[sys.maxsize for _ in range(N)] for _ in range(N)]
        bracket = [[0 for _ in range(N)] for _ in range(N)]

        for i in range(N - 1, 0, -1):
            for j in range(N):
                if i == j:
                    dp[i][j] = 0
                else:
                    for k in range(i, j):
                        cost = arr[i - 1] * arr[k] * \
                            arr[j] + dp[i][k] + dp[k + 1][j]
                        if cost < dp[i][j]:
                            dp[i][j] = cost

                            bracket[i][j] = k

        # print("Optimal Parenthesization is : ")
        printParenthesis(1, N - 1, N, bracket)
        # print(res)
        # return dp[1][N - 1]
        return "".join(res)


def main():
    # arr = [40, 20, 30, 10, 30]
    arr =[36, 49, 4, 36, 16, 41, 27, 40, 21, 20, 5, 48]

    solution = Solution()
    print(f"ans is {solution.matrixMultiplication(len(arr), arr)}")


if __name__ == "__main__":
    main()
