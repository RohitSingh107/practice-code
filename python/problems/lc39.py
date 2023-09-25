# https://leetcode.com/problems/combination-sum/
from typing import List, Deque
from collections import deque
# from itertools import combinations_with_replacement


def f(i, t, candidates : List[int], tmp : Deque[int], all_comb : Deque[Deque[int]]):

    if t == 0:
        all_comb.append(tmp.copy())
        return

    if i < 0:
        return

    # Take
    if t - candidates[i] >= 0: 
        tmp.append(candidates[i])
        f(i, t - candidates[i], candidates, tmp, all_comb)
        tmp.pop()

    # Not Take
    f(i-1, t, candidates, tmp, all_comb)

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        tmp = deque()
        all_comb = deque()

        f(len(candidates) -1 , target, candidates, tmp, all_comb)
        return all_comb













def main():
    # candidates = [2,3,6,7]
    # target = 7
    candidates = [2,3,5]
    target = 8
    solution = Solution()
    print(f"ans is {solution.combinationSum(candidates, target)}")

if __name__ == '__main__':
    main()
