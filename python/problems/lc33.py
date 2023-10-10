# https://leetcode.com/problems/search-in-rotated-sorted-array/description/
from pprint import pprint
from typing import List, Deque
from collections import deque






class Solution:
    def search(self, nums: List[int], target: int) -> int:

        l = 0
        h = len(nums) - 1

        while l < h:
            m = (l + h) // 2

            if nums[m] == target:
                return m
            elif nums[l] < nums[h]:
                if nums[m] < target:
                    l = m + 1
                else:
                    h = m - 1
            else:
                # if (nums[h] >= target and target < nums[l]) or nums[m] < target:
                if nums[m] < nums[h]:
                    if nums[m] <= target <= nums[h]:
                        l = m + 1
                    else:
                        h = m - 1
                else:
                    if nums[m+1] > nums[m]:
                        if target > nums[m] or target < nums[l]:
                            l = m + 1
                        else:
                            h = m - 1
                    else:
                        if nums[l] <= target <= nums[m]:
                            h = m - 1
                        else:
                            l = m + 1

        if nums[l] == target:
            return l
        return -1





def main():
    nums = [4,5,6,7,0,1,2]
    target = 0
    # nums = [1,3]
    # target = 3
    # nums = [5,1,3]
    # target = 3
    # nums = [4,5,6,7,8,1,2,3]
    # target = 8
    # nums = [3,4,5,6,1,2]
    # target = 2

    solution = Solution()
    ans = solution.search(nums, target)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
