# https://leetcode.com/problems/majority-element-ii/

from typing import List
from collections import Counter
import math
#
# def majorityElement(nums: List[int]) -> List[int]:
#
#     if len(nums) <= 1:
#         return nums
#
#     cnt1 = 0
#     cnt2 = 0
#
#     el1 = None
#     el2 = None
#
#     for i in nums:
#         if cnt1 == 0 and el2 != i:
#             print(f"el1 is {el1}, el2 is {el2}")
#
#             cnt1 = 1
#             el1 = i
#         elif cnt2 == 0 and el1 != i:
#             cnt2 = 1
#             el2 = i
#         elif i == el1:
#             cnt1 += 1
#         elif i == el2:
#             cnt2 += 1
#         else:
#             cnt1 -= 1
#             cnt2 -= 1
#
#     c = Counter(nums)
#     
#
#     # print(f"el1 is {el1}, el2 is {el2}")
#
#     ans = []
#
#     if el2 is not None and c.get(el2) > math.floor(len(nums) / 3):
#         ans.append(el2)
#     if el1 is not None and c.get(el1) > math.floor(len(nums) / 3):
#         ans.append(el1)
#
#     ans.reverse()
#     return ans
#

def majorityElement(nums: List[int]) -> List[int]:

    if len(nums) <= 1:
        return nums

    c = Counter(nums)
    return [elm for elm, cnt in c.items() if cnt > math.floor(len(nums) / 3)]
    


nums = [1,2]

print(majorityElement(nums))

