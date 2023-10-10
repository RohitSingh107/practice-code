# https://leetcode.com/problems/single-element-in-a-sorted-array/description/
from pprint import pprint
from typing import List, Deque
from collections import deque



class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:

 

        n = len(nums)

        if n == 1:
            return nums[0]

        low = 0
        hi = n - 1

        while True:
            mid = (low + hi ) // 2

            print(low, mid, hi)
            if (mid == 0 or nums[mid] != nums[mid - 1]) and (mid == n -1 or nums[mid] != nums[mid+1]):
                return nums[mid]
            elif ((nums[mid] == nums[mid - 1] and ((mid + 1) & 1))) or (nums[mid] != nums[mid-1] and (mid & 1)):
                hi = mid - 1
            else:
                low = mid + 1



def main():
    solution = Solution()
    nums = [1,1,2,3,3,4,4,8,8]
    # nums = [3,3,7,7,10,11,11]
    # nums = [1,1,2]
    # nums = [7,7,10,11,11,12,12]
    ans = solution.singleNonDuplicate(nums)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
