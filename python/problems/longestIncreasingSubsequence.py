# https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

from typing import List

def lis(i : int, a : List[int], dp : List[int]) -> int:

    if dp[i] != -1:
        return dp[i]

    ans = 1

    for j in range(i):
        if a[i] > a[j]:
            ans = max(ans, lis(j, a, dp) +1)

    dp[i] = ans
    return dp[i]


def longestSubsequence(n : int,a : List[int]) -> int:

    ans = 1

    
    # # TopDown Recursion
    # dp = [-1 for _ in range(n)]
    # for i in range(n):
    #     ans = max(ans, lis(i,a, dp))
    # return ans

    # BottomUp Tabulation
    dp= [1 for _ in range(n)]
    for i in range(n):
        for j in range(i):
            if a[i] > a[j]:
                dp[i] = max(dp[i], dp[j] +1)
        ans = max(ans, dp[i])
    return ans

def main():
    a = [0,8,4,12,2,10,6,14,1,9,5, 13,3,11,7,15]

    print(longestSubsequence(16, a))

main()
