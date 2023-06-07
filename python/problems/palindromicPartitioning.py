from collections import deque
import sys
from typing import List, Deque


len = len


def isPalindrome(i, j, s ):
    if i == "" and s[i] == '':
        return False
    while j > i:
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1

    return True


def f(i, n, s, dp):
    if i > n:
        return 0

    # print(f"i is {i}, n is {n}")
    if dp[i] != -1:
        return dp[i]

    dp[i] = sys.maxsize
    for j in range(i, n+1):
        if isPalindrome(i, j, s):
            part = 1 + f(j+1, n, s, dp)
            dp[i] = min(dp[i], part)

    # print(dp)

    return dp[i]



class Solution:
    def palindromicPartition(self, string: str) -> int:

        l = len(string)
        # dp = [-1 for _ in range(l)]
        # return f(0, l -1, string, dp) - 1 # It counts substrings so minus to get partition

        dp = [0 for _ in range(l+1)]

        for i in range(l-1, -1, -1):
            dp[i] = sys.maxsize
            for j in range(i, l):
                # print(f"i is {i}, j is {j}")
                if isPalindrome(i, j, string):
                    part = 1 + dp[j+1]
                    dp[i] = min(dp[i], part)

        print(dp)
        return dp[0] - 1





def main():
    # str = "ababbbabbababa"
    # str = "abcde"
    str = "aaabba"
    solution = Solution()
    print(f"ans is {solution.palindromicPartition(str)}")

if __name__ == '__main__':
    main()
