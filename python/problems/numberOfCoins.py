from collections import deque
from typing import List, Deque
import sys



def f(v : int, c : int, coins : List[int]) -> int | None:

    if v == 0:
        return 0
    if c == -1:
        return None
 
    if v - coins[c] >= 0:
        take = f(v - coins[c], c, coins)
        not_take = f(v, c - 1, coins)
        if take is None:
            return not_take
        elif not_take is None:
            return take + 1
        else:
            return min(take + 1, not_take)
    return f(v, c -1, coins)

# https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
class Solution:
    def minCoins(self, coins : List[int], M : int, V : int) -> int:
		# code here

        # ans = f(V, len(coins) - 1, coins)
        # return ans or -1
        dp = [[sys.maxsize for _ in range(M + 1)] for _ in range(V+1)]
        for v in range(V+1):
            for c in range(M):
                if v == 0:
                    dp[v][c] = 0
                    continue
                if v - coins[c] >= 0:
                    dp[v][c] = min(dp[v - coins[c]][c] +1, dp[v][c-1])
                else:
                    dp[v][c] = dp[v][c-1]
        # print(dp)
        return dp[V][M - 1] if dp[V][M - 1] != sys.maxsize else -1






def main():

    # V = 11
    # M = 4
    # coins = [9,6,5,1]

    V = 30
    M = 3
    coins = [25, 10, 5]
    solution = Solution()
    print(f"ans is {solution.minCoins(coins, M, V)}")

if __name__ == '__main__':
    main()
