from collections import deque
from typing import List, Deque






# https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
class Solution:
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,n : int, arr : List[int] ,dep : List[int]):
        # code here

        arr.sort()
        dep.sort()

        a = 0
        d = 0

        p = 0
        ans = p

        while a < n:
            if arr[a] > dep[d]:
                p -= 1
                d += 1
            else:
                p += 1
                a += 1
            ans = max(ans, p)
        return ans








def main():
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]
    solution = Solution()
    print(f"ans is {solution.minimumPlatform(len(arr), arr, dep)}")

if __name__ == '__main__':
    main()
