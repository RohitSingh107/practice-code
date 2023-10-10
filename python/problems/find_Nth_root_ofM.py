# https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
from pprint import pprint
from typing import List, Deque
from collections import deque





class Solution:
    def NthRoot(self, n : int, m : int):
        # Code here

        low = 1
        hi = m

        while low < hi:

            mid = (low + hi) // 2

            t = mid ** n

            if t < m:
                low = mid + 1
            elif t > m:
                hi = mid - 1
            else:
                return mid

        if low ** n == m:
            return low
        return -1








def main():
    n = 2
    m = 9
    solution = Solution()
    ans = solution.NthRoot(n,m)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
