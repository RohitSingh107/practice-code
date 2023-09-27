# https://leetcode.com/problems/permutations/
from typing import List, Deque
from collections import deque
from pprint import pprint


def permutations(nums : List[int], ds : Deque[int], all_perms : Deque[Deque[int]]):

    if nums == []:
        all_perms.append(ds.copy())
        return

    for num in nums:
        ds.append(num)
        permutations([i for i in nums if i != num], ds, all_perms)
        ds.pop()

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]] | Deque[Deque[int]]:
        ds = deque()
        all_perms = deque()
        permutations(nums, ds, all_perms)
        return all_perms






def main():
    nums = [1,2,3]
    solution = Solution()
    ans = solution.permute(nums)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
