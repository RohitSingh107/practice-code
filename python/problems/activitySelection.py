from collections import deque
from typing import List, Deque







# https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
class Solution:
    #Function to find the maximum number of activities that can
    #be performed by a single person.
    def activitySelection(self,n : int,start : List[int],end : List[int]):
        # code here

        times = sorted(zip(start, end), key= lambda x : x[1])
        # print(times)
        ans = 1
        e = times[0][1]
        for i in range(1, n):
            if times[i][0] > e:
                ans += 1
                e = times[i][1]
        return ans









def main():
    start = [1, 3, 2, 5]
    end = [2, 4, 3, 6]
    solution = Solution()
    print(f"ans is {solution.activitySelection(len(start), start, end)}")

if __name__ == '__main__':
    main()
