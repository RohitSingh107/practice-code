# https://practice.geeksforgeeks.org/problems/subset-sums2234/1
from typing import List, Deque
from itertools import combinations
from collections import deque



def f(i : int, arr : List[int], s : int, all_ss : Deque[int]):

    if i < 0:
        # print(tmp)
        all_ss.append(s)
        return

    # Take
    # tmp.append(arr[i])
    f(i -1, arr, s + arr[i], all_ss)

    # Not Take
    f(i - 1, arr, s, all_ss)

# class Solution:
#     def subsetSums(self, arr : List[int], N : int):
#
#         all_ss = deque()
#
#         for r in range(N +1):
#             combs = list(combinations(arr, r))
#             print(combs)
#             all_ss.extend(combs)
#         # print(set(all_ss))
#         return list(sorted(map(lambda x : sum(x), all_ss)))

class Solution:
    def subsetSums(self, arr : List[int], N : int):

        all_ss = deque()
        f(N-1, arr, 0, all_ss)
        return list(all_ss)



def main():
    arr = [5,2,1]
    # arr = [1,2,2]
    solution = Solution()
    ans = solution.subsetSums(arr, len(arr))
    print(ans)

if __name__ == '__main__':
    main()
