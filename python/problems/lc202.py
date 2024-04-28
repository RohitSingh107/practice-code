
from pprint import pprint
from typing import List, Deque
from collections import deque, defaultdict


def f(n : int, visited) -> bool:
    if visited[n]:
        return False

    visited[n] = True

    ans = 0
    while n:
        r = n % 10
        ans += (r * r)
        n = n // 10
    
    if ans == 1:
        return True
    return f(ans, visited)

class Solution:
    def isHappy(self, n: int) -> bool:
        visited = defaultdict(bool)
        return f(n, visited)






def main():
    # n = 19
    n = 2
    solution = Solution()
    ans = solution.isHappy(n)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
