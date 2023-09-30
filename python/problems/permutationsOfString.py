# https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
from typing import List, Deque
from collections import deque
from pprint import pprint


def permutation(
    s: List[str], selected: List[bool], ds: Deque[str], all_perms: Deque[str]
):
    if len(ds) == len(s):
        all_perms.append("".join(ds))
        return

    for i in range(len(s)):
        if (i > 0 and s[i] == s[i - 1] and not selected[i - 1]):  # if it is alreadey selected/taken I will not consider it in remaining/availavle string. if previous and this both are selected they are identical and will have exact same effect but if previous is alreadey selected then both will have different effects.
            continue

        if not selected[i]:
            selected[i] = True
            ds.append(s[i])
            permutation(s, selected, ds, all_perms)
            ds.pop()
            selected[i] = False


class Solution:
    def find_permutation(self, S: str):
        # Code here

        s = sorted(S)

        ds = deque()
        all_perms = deque()
        selected = [False] * len(S)
        permutation(s, selected, ds, all_perms)
        return all_perms


def main():
    s = "ABC"
    # s = "ABB"
    solution = Solution()
    ans = solution.find_permutation(s)
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
