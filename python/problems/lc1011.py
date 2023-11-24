from collections import deque
from typing import List, Deque



def daysRequired(mid : int, days : int, weights : List[int]) -> int:
    days_required = 1
    current_weight = 0

    for w in weights:
        if current_weight + w <= mid:
            current_weight += w
        else:
            days_required += 1
            current_weight = w

            if days_required > days:
                return days_required


    return days_required


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        
        lo = max(weights)
        hi = sum(weights)

        while lo <= hi:
            mid = (lo +hi) // 2

            if daysRequired(mid, days, weights) <= days:
                hi = mid - 1
            else:
                lo = mid + 1
        return lo










def main():
    # weights = [1,2,3,4,5,6,7,8,9,10]
    # days = 5

    weights = [3,2,2,4,1,4]
    days = 3

    weights = [1,2,3,1,1]
    days = 4

    solution = Solution()
    print(f"ans is {solution.shipWithinDays(weights, days)}")

if __name__ == '__main__':
    main()
