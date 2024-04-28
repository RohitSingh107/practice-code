
from pprint import pprint
from typing import List, Deque
from collections import deque




def f(num: int) -> int:
    ans = 0
    while num:
        ans += (num % 10)
        num = num // 10

    if ans // 10 != 0:
        return f(ans)
    return ans

class Solution:
    def addDigits(self, num: int) -> int:
        return f(num)








def main():
    num = 38
    solution = Solution()
    ans = solution.addDigits(num)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
