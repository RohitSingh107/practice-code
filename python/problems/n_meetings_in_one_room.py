from collections import deque
from typing import List, Deque







# https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
class Solution:
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,n,start,end):

        c= 0
        e = end[0]
        for i in range(n):

            if i == 0:
                c = 1
                continue
            s = start[i]
            if s > e:
                c += 1
                e = end[i]
        return c








def main():
    N = 6
    start = [1,3,0,5,8,5]
    end =  [2,4,6,7,9,9]
    solution = Solution()
    print(f"ans is {solution.maximumMeetings(N, start, end)}")

if __name__ == '__main__':
    main()
