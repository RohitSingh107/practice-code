# https://leetcode.com/problems/combination-sum-iii/
from pprint import pprint
from typing import List, Deque
from collections import deque



def combsum(i : int, k : int, n : int, ds : Deque[int], all_comb : Deque[Deque[int]]):

    if n == 0 and len(ds) == k:
        all_comb.append(ds.copy())
        return

    if len(ds) == k:
        return

    for j in range(i, 9 + 1):

        if j > n:
            break

        ds.append(j)
        combsum(j+1, k, n - j, ds, all_comb)
        ds.pop()


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]] | Deque[Deque[int]]:

        ds = deque()
        all_comb = deque()

        combsum(1, k, n, ds, all_comb)
        return all_comb






def main():
    k = 3;
    n = 9;
    solution = Solution()
    ans = solution.combinationSum3(k,n)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
