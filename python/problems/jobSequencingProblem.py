from collections import deque, defaultdict
from typing import List, Deque




# https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
class Solution:
    #Function to find the maximum profit and the number of jobs done.
    def JobScheduling(self,Jobs : List,n):
        Jobs.sort(key= lambda x : x.profit, reverse = True)

        slots = defaultdict(bool)
        profits = 0
        c = 0

        for j in Jobs:
            d = j.deadline
            while True:
                if not slots[d]:
                    slots[d] = True
                    profits += j.profit
                    c += 1
                    # print(d, j.profit)
                    break
                d -= 1
                if d == 0:
                    break
        # print(slots)
        return c, profits

def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
