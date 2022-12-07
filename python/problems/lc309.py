# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

from typing import List

def f(i : int, buy : bool, prices : List[int]) -> int:

    # print(f"1. i is {i}, buy is {buy}")

    if i >= len(prices):
        return 0

    if buy:
        return max(f(i+1, False, prices) - prices[i], f(i+1, True, prices) - 0) # Buy and not buy
    else:
        # print(f"2. i is {i}, buy is {buy}")
        return max(f(i+2, True, prices) + prices[i], f(i+1, False, prices) + 0) # sell and not sell






def maxProfit(prices: List[int]) -> int:

#     # TopDown Recursion
#     return f(0, True, prices)
     
    # # BottomUp Tabulation
    # n = len(prices)
    # dp = [[0 for _ in range(2)] for _ in range(n+2)]

    # for i in range(n-1, -1, -1):
    #         dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1])
    #         dp[i][0] = max(dp[i+2][1] + prices[i], dp[i+1][0])
    # return dp[0][1]   

    # BottomUp Space Optimized
    n = len(prices)
    # dp = [[0 for _ in range(2)] for _ in range(n+2)]
    curr = [0 for _ in range(2)]
    front1 = [0 for _ in range(2)]
    front2 = [0 for _ in range(2)]

    for i in range(n-1, -1, -1):
            curr[1] = max(front1[0] - prices[i], front1[1])
            curr[0] = max(front2[1] + prices[i], front1[0])

            front2 = front1.copy()
            front1 = curr.copy()

    print(curr)
    print(front1)
    print(front2)

    return curr[1]
    




if __name__ == "__main__":
    prices : List[int] = [1,2,3,0,2]
    # prices = [1,2]
    print(maxProfit(prices))


