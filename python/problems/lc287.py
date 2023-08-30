# https://leetcode.com/problems/find-the-duplicate-number/
from typing import List
from collections import defaultdict

import operator as op


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:

        sp = nums[nums[0]]
        fp = nums[nums[nums[0]]] # firsr iteration of both pointer here
        while sp != fp:
            print(f"sp is {sp}, fp is {fp}")
            sp = nums[sp]
            fp = nums[nums[fp]]

        fp = nums[0]

        while sp != fp:
            sp = nums[sp]
            fp = nums[fp]

        return sp




def main():
    nums = [3,1,3,4,2]
    # nums = [1,3,4,2,2]
    # nums = [2,5,9,6,9,3,8,9,7,1]
    solution = Solution()
    print(f"ans is {solution.findDuplicate(nums)}")

if __name__ == '__main__':
    main()



# def findDuplicate(self, nums: List[int]) -> int:
#
#     # x = reduce(op.xor,range(1,len(nums)),0)
#     #
#     # return reduce(op.xor, nums, x)
#
#     d = defaultdict(bool)
#
#     for n in nums:
#         if d[n]:
#             return n
#         else:
#             d[n] = True
#
#

