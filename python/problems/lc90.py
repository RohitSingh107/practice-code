
from typing import Deque, List

from itertools import combinations
from collections import deque
from pprint import pp, pprint

# class Solution:
#     def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
#         all_ss = deque()
#
#         for r in range(len(nums) +1):
#             combs = list(combinations(nums, r))
#             all_ss.extend(map(tuple, map(sorted, combs)))
#         return set(all_ss)
#
#

def subset(i : int, nums : List[int], ds : Deque[int], all_ss : Deque[Deque[int]]):

    if i >= len(nums):
        print("ds is ", ds)
        all_ss.append(ds.copy())
        return

    # ds.append(nums[i])
    # subset(i +1, nums, ds, all_ss)
    # ds.pop()
 
    for j in range(i, len(nums)):
        if j > i and nums[j] == nums[j-1]:
            continue
        # Take
        ds.append(nums[j])
        subset(j + 1, nums, ds, all_ss)
        ds.pop()

    subset(i +1, nums, ds, all_ss)

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ds = deque()
        all_ss = deque()
        nums.sort()
        subset(0, nums, ds, all_ss)
        # print(len(all_ss))
        return list(all_ss)



def main():
    # nums = [4,4,4,1,4]
    nums = [1,2,2]
    solution = Solution()
    ans = solution.subsetsWithDup(nums)
    # for i in ans:
    #     pprint(i)
    # pprint(f"ans is {solution.subsetsWithDup(nums)}")

if __name__ == '__main__':
    main()
