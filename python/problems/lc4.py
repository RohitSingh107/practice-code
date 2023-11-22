
# https://leetcode.com/problems/median-of-two-sorted-arrays/description/
from collections import deque
from typing import List, Deque

import sys

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        n1 = len(nums1)
        n2 = len(nums2)

        if n1 < n2:
            shorter, longer = nums1, nums2
        else:
            shorter, longer = nums2, nums1

        part = (n1 + n2 + 1) // 2
        lo = 0
        hi = len(shorter)

        while lo <= hi:
            mid = (lo + hi) // 2

            lu = shorter[mid - 1] if mid != 0 else (-sys.maxsize)
            ld = longer[part - mid - 1] if (part - mid - 1) >= 0 else (-sys.maxsize)

            ru = shorter[mid] if mid < len(shorter) else sys.maxsize
            rd = longer[part - mid] if (part - mid) < len(longer) else sys.maxsize

            if lu > rd:
                hi = mid - 1
            elif ld > ru:
                lo = mid + 1
            else:
                if (n1 + n2) & 1:
                    return max(lu,ld)
                return (max(lu, ld) + min(ru, rd)) / 2

        return 0

 











def main():

    # nums1 = [1,2,2]
    # nums2 = [2,4,4]

    # nums1 = [5,7]
    # nums2 = [2,4,8,10,11]

    nums1 = [1,3]
    nums2 = [2,4,6]

    # nums1 = [1,3,5]
    # nums2 = [2,4,6]
    #
    solution = Solution()
    print(f"ans is {solution.findMedianSortedArrays(nums1, nums2)}")

if __name__ == '__main__':
    main()
