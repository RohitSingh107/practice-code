from pprint import pprint
from typing import List, Deque
from collections import deque


romans = {
    "I": (0, 1),
    "V": (1, 5),
    "X": (2, 10),
    "L": (3, 50),
    "C": (4, 100),
    "D": (5, 500),
    "M": (6, 1000),
}


class Solution:
    def romanToInt(self, s: str) -> int:

        ans = 0


        for i in range(len(s) -1):
            sign = 1 if romans[s[i]][0] >= romans[s[i+1]][0] else -1

            ans += (sign * romans[s[i]][1])

        return ans + romans[s[-1]][1]


def main():
    s = "MCMXCIV"
    # s = "LVIII"

    solution = Solution()
    ans = solution.romanToInt(s)
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
