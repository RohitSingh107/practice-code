# https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
from typing import List, Deque
from collections import deque
from pprint import pprint
from itertools import permutations


def perm(
    s: str, selected: List[bool], ds: Deque[str], all_perms: Deque[str]
):
    if len(ds) == len(s):
        all_perms.append("".join(ds))
        return

    for i in range(len(s)):

        if not selected[i]:
            selected[i] = True
            ds.append(s[i])
            perm(s, selected, ds, all_perms)
            ds.pop()
            selected[i] = False


# class Solution:
#     def permutation(self, s: str):
#         # Code here
#
#         # s = sorted(S)
#
#         ds = deque()
#         all_perms = deque()
#         selected = [False] * len(s)
#         perm(s, selected, ds, all_perms)
#         return sorted(all_perms)
#

class Solution:
    def permutation(self, s: str):
        # Code here
        return sorted(map("".join, permutations(s)))

 


def main():
    # s = "AAA"
    # s = "ABSG"
    # s = "ABB"
    s = "PRJJX"
    solution = Solution()
    ans = solution.permutation(s)
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
