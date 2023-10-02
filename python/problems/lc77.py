# https://leetcode.com/problems/combinations/description/
from typing import List, Deque
from collections import deque
from pprint import pprint
from itertools import combinations

len = len

def comb(i : int, n : int, k : int, ds : Deque[int], all_comb : Deque[Deque[int]]):
 
    if len(ds) == k:
        all_comb.append(ds.copy())
        return

    for j in range(i, n+1):

        ds.append(j)
        comb(j+1, n, k, ds, all_comb)
        ds.pop()






class Solution:
    def combine(self, n: int, k: int) -> List[List[int]] | Deque[Deque[int]]:

        # return list(combinations(range(1, n+1), k)) 

        ds = deque()
        all_comb = deque()

        comb(1, n, k, ds, all_comb)
        return all_comb








def main():
    n = 4
    k = 2
    solution = Solution()
    ans = solution.combine(n, k)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
