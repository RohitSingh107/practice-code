# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

from typing import List

def f(i : int, buy : bool, prices : List[int]) -> int:

    if i >= len(prices):
        return 0

    if buy:
        return max(f(i+1, False, prices) - prices[i], f(i+1, True, prices) - 0) # Buy and not buy
    else:
        return max(f(i+2, True, prices) + prices[i], f(i+1, False, prices) + 0) # sell and not sell






def maxProfit(prices: List[int], fee : int) -> int:

#     # TopDown Recursion
#     return f(0, True, prices)
     
    # BottomUp Tabulation
    # n = len(prices)
    # dp = [[0 for _ in range(2)] for _ in range(n+1)]

    # for i in range(n-1, -1, -1):
    #         dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1])
    #         dp[i][0] = max(dp[i+1][1] + prices[i] - fee, dp[i+1][0])
    # return dp[0][1]   

    # BottomUp Space Optimized
    n = len(prices)
    curr = [0 for _ in range(2)]
    front = [0 for _ in range(2)]

    for i in range(n-1, -1, -1):
            curr[1] = max(front[0] - prices[i], front[1])
            curr[0] = max(front[1] + prices[i] - fee, front[0])

            front= curr.copy()

    return curr[1]
    




if __name__ == "__main__":
    prices : List[int] = [1,3,2,8,4,9]
    # prices = [1,2]
    print(maxProfit(prices, 2))


