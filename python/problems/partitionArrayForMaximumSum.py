from collections import deque
from typing import List, Deque


import sys


def f(i, n, k, arr, dp):

    if i > n:
        return 0

    if dp[i] != -1:
        return dp[i]
    
    ans = sys.maxsize

    ans = -sys.maxsize -1
    max_elem = -sys.maxsize -1
    part_size = 0
    
    for j in range(k):
        if i + j > n:
            continue
        max_elem = max(max_elem, arr[i + j])
        part_size += 1

        curr_part = max_elem * part_size + f(i + j + 1 , n, k, arr, dp)

        ans = max(ans, curr_part)

    dp[i] = ans

    # print(dp)

    return dp[i]



class Solution:
    def solve(self, n, k, arr):

        # Code here
        # dp = [-1 for _ in range(n)]
        # return f(0, n-1, k, arr, dp)
        dp = [0 for _ in range(n +1)]
        for i in range(n-1, -1, -1):
            dp[i] = -sys.maxsize -1
            max_elem = -sys.maxsize -1
            part_size = 0

            for j in range(k):
                if i + j > n -1:
                    continue
                # print(f"i is {i}, j is {j}")
                max_elem = max(max_elem, arr[i+j])
                part_size += 1
                curr_part = max_elem * part_size + dp[i+j +1]
                dp[i] = max(dp[i], curr_part)
    
        # print(dp)
        return dp[0]








def main():
    n = 7
    k = 3
    arr = [1,15,7,9,2,5,10]

    solution = Solution()
    print(f"ans is {solution.solve(n, k, arr)}")

if __name__ == '__main__':
    main()
