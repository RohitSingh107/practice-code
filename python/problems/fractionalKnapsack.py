from collections import deque
from typing import List, Deque


# https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
class Item:
    def __init__(self,val,w):
        self.value = val
        self.weight = w

class Solution:
    def fractionalknapsack(self, W : int, arr : List[Item],  n : int):
        # code here

        arr.sort(reverse= True, key= lambda x : (x.value / x.weight))
        
        profit = 0

        for i in arr:
            if W <= 0:
                break

            if W - i.weight >= 0:
                profit += i.value
                W -= i.weight
            else:
                profit += (i.value * W / i.weight)
                W = 0
        return profit











def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
