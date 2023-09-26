# https://leetcode.com/problems/combination-sum/
from typing import List, Deque, Tuple, Set
from collections import deque
# from itertools import combinations_with_replacement
from pprint import pp, pprint



def subset(i : int, target : int, candidates : List[int], ds : Deque[int], ss : Deque[Deque[int]]):

    if target == 0:
        ss.append(ds.copy())
        return

    if i >= len(candidates):
        return

 
 
    for j in range(i, len(candidates)):
        if j > i and candidates[j] == candidates[j-1]:
            continue

        if candidates[j] > target:
            break
        ds.append(candidates[j])
        subset(j + 1, target - candidates[j], candidates, ds, ss)
        ds.pop()


class Solution:
    def combinationSum(self, candidates: List[int], target: int):

        ds = deque()
        ss = deque()
        candidates.sort()

        subset(0, target, candidates, ds, ss)
        return ss













def main():
    # candidates = [2,3,6,7]
    # target = 7
    # candidates = [2,3,5]
    target = 8
    candidates = [10,1,2,7,6,1,5]
    # candidates = [1,2, 5, 1]
    solution = Solution()
    ans = solution.combinationSum(candidates, target)
    pprint(ans)

if __name__ == '__main__':
    main()
