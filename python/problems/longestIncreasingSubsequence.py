# https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

from typing import List

def upperBound(l : List[int], n : int) -> int:
    if n < l[0]:
        return 0

    size : int = len(l)
    lo : int = 0
    hi : int = size - 1

    while hi > lo:
        mid : int = (lo + hi)//2
        if l[mid] <= n:
            lo = mid + 1
        else:
            hi = mid 
        
    if lo < size and l[lo] <= n:
        lo += 1

    return lo


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

def lis_bs(n: int, a : List[int]) -> int:

    dp = [100000000000000000 for _ in range(n+1)] 
    dp[0] = -100000000000000000
    for i in range(0,n):
        pos : int = upperBound(dp, a[i])

        if a[i] < dp[pos] and a[i] > dp[pos-1]:
            dp[pos] = a[i]

    for i in range(n, -1, -1):
        if dp[i] != 100000000000000000:
            return i
    return 1


def main():
    # a = [0,8,4,12,2,10,6,14,1,9,5, 13,3,11,7,15]
    a = [10,5,8,3,9,4,12,11]

    # print(longestSubsequence(16, a))
    print(lis_bs(len(a), a))

main()
