# https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
from collections import deque
from typing import List, Deque







class Solution:
    #Function to find if there is a celebrity in the party or not.
    def celebrity(self, M : List[List[int]], n : int):
        # code here 

        s : Deque[int] = deque()

        for i in range(n):
            s.append(i)

        while len(s) > 1:

            a = s.pop()
            b = s.pop()

            if M[a][b]:
                s.append(b)
            else:
                s.append(a)

        c = s.pop()

        for i in range(n):

            if M[c][i]:
                return -1

            if not M[i][c] and i != c:
                return -1

        return c







def main():

    N = 3
    M = [[0, 1, 0],
         [0, 0, 0], 
         [0, 1, 0]]
    solution = Solution()
    print(f"ans is {solution.celebrity(M, N)}")

if __name__ == '__main__':
    main()
