# https://leetcode.com/problems/letter-combinations-of-a-phone-number/
from pprint import pprint
from typing import List, Deque
from collections import deque
from itertools import product


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        m = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        ds = [m[d] for d in digits]
        # print(ds)

        return list(map("".join, product(*ds))) 



def main():
    solution = Solution()
    digits = "23"
    ans = solution.letterCombinations(digits)
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
