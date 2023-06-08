from collections import deque
from typing import List, Deque
import sys


len = len

def histogram_area(arr : List[int]) -> int:
    # print(arr, end=" ")
    s = deque()
    
    maxA = 0
    n = len(arr)
    for i in range(n+1):
        while len(s) > 0 and (i == n or arr[s[0]] >= arr[i]):
            height = arr[s.popleft()]
            
            if len(s):
                width = i - s[0] - 1
            else:
                width = i

            maxA = max(maxA, width * height)

        s.appendleft(i)

    # print("Area  is ", maxA)
    return maxA



class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        row = len(matrix)
        col = len(matrix[0])

        prev_row = [0 for _ in range(col)]

        ans = -sys.maxsize -1

        for r in range(row):
            # print(f"r is {r}")
            for c in range(col):
                if matrix[r][c] == "1":
                    prev_row[c] += 1
                else:
                    prev_row[c] = 0

            ans = max(ans, histogram_area(prev_row))

        return ans
    


def main():
    matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"], ["1","0","0","1","0"]]
    solution = Solution()
    print(f"ans is {solution.maximalRectangle(matrix)}")

if __name__ == '__main__':
    main()
