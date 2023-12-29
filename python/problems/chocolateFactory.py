
from pprint import pprint
from typing import List, Deque
from collections import deque


class Solution:


    def solve(self, arr : List[int]) -> List[int]:

        ind = 0

        for i in range(len(arr)):
            if arr[i] != 0:
                arr[i], arr[ind] = arr[ind], arr[i]
                ind += 1

        return arr







def main():
    arr = [4,5,0,1,9,0,5,0]
    solution = Solution()
    ans = solution.solve(arr)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
