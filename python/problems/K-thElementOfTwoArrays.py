# https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
from collections import deque
from typing import List, Deque

import sys






class Solution:
    def kthElement(self,  arr1, arr2, n, m, k):
        
        if m < n:
            return self.kthElement(arr2, arr1, m, n, k)

        lo = max(0, k - m)
        hi = min(len(arr1), k)

        while lo <= hi:
            mid = (lo +hi) // 2

            lu = arr1[mid - 1] if mid != 0 else (-sys.maxsize)
            ld = arr2[k - mid - 1] if (k - mid - 1) >= 0 else (-sys.maxsize)

            ru = arr1[mid] if mid < n else sys.maxsize
            rd = arr2[k - mid] if (k - mid) < m else sys.maxsize

            if lu > rd:
                hi = mid - 1
            elif ld > ru:
                lo = mid + 1
            else:
                return max(lu, ld)






def main():
    # arr1 = [2, 3, 6, 7, 9]
    # arr2 = [1, 4, 8, 10]
    # k = 5

    # arr1 = [100, 112, 256, 349, 770]
    # arr2 = [72, 86, 113, 119, 265, 445, 892]
    # k = 7

    # arr1 = list(map(int, "5 5 8 8 8 9 11 11 11 11 11".split()))
    # arr2 = list(map(int, "4 4 4 4 6 8 9 9 9 11 13".split()))
    # k = 2

    arr1 = [2,7,10]
    arr2= [4,5,7,8,10]
    k = 6

    solution = Solution()
    print(f"ans is {solution.kthElement(arr1, arr2, len(arr1), len(arr2), k)}")

if __name__ == '__main__':
    main()
