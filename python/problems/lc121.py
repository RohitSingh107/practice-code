from collections import deque
from typing import List, Deque







class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        ans = 0
        curMin = prices[0]
        for i in prices:
            if i < curMin:
                curMin = i
            ans = max(ans, i - curMin)


        return ans






def main():
    # prices = [7,1,5,3,6,4]
    prices = [7,6,4,3,1]
    solution = Solution()

    print(f"ans is {solution.maxProfit(prices)}")

if __name__ == '__main__':
    main()
