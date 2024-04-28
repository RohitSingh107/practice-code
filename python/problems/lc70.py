
from pprint import pprint
from typing import List, Deque
from collections import deque




def climb(p : int, n : int) -> int:
    if p == n:
        return 1
    if p > n:
        return 0
    return climb(p +1, n) + climb(p + 2, n)


class Solution:
    def climbStairs(self, n: int) -> int:
        # return climb(0, n)

        c = 0
        c1 = 0
        c2 = 0

        for i in range(n, -1, -1):
            if i == n:
                c1 = 1
                continue
            c = c1 + c2

            c2 = c1
            c1 = c

        return c







def main():
    n = 2
    solution = Solution()
    ans = solution.climbStairs(n)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
