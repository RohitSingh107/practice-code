# https://leetcode.com/problems/longest-common-subsequence/description/
from collections import deque
from typing import List, Deque






def lcs(i : int, j : int, s1 : str, s2 : str, dp) -> int:
    if i == 0 or j == 0:
        return 0
    if dp[i][j] != -1:
        return dp[i][j]

    if s1[i-1] == s2[j-1]:
        dp[i][j] = 1 + lcs(i-1, j -1, s1, s2, dp)
        return dp[i][j]

    dp[i][j] = max(lcs(i -1, j, s1, s2, dp), lcs(i, j -1, s1, s2, dp))
    return dp[i][j]

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        # dp = [[-1 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]
        # return lcs(len(text1), len(text2), text1, text2, dp)

        dp = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]
        
        for i in range(1, len(text1) + 1):
            for j in range(1, len(text2) + 1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[len(text1)][len(text2)]





def main():
    text1 = "abcde"
    text2 = "ace"
    solution = Solution()
    print(f"ans is {solution.longestCommonSubsequence(text1, text2)}")

if __name__ == '__main__':
    main()
