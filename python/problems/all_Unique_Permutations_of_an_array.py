# https://practice.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
from typing import List, Deque
from collections import deque
from pprint import pprint

from itertools import permutations



def perms(arr : List[int], selected : List[bool], ds : Deque[int], all_perms : Deque[Deque[int]]):

    if len(ds) == len(arr):
        all_perms.append(ds.copy())
        return

    for i in range(len(arr)):

        if i > 0 and arr[i] == arr[i-1] and not selected[i-1]: # if it is alreadey selected/taken I will not consider it in remaining/availavle string. if previous and this both are selected they are identical and will have exact same effect but if previous is alreadey selected then both will have different effects.
            continue

        if not selected[i]:
            ds.append(arr[i])
            selected[i] = True
            perms(arr, selected, ds, all_perms)
            selected[i] = False
            ds.pop()


# class Solution:
#     def uniquePerms(self, arr, n):
#         # code here 
#
#         arr.sort()
#
#         ds = deque()
#         all_perms = deque()
#         selected = [False] * n
#
#         perms(arr, selected, ds, all_perms)
#
#         return all_perms

class Solution:
    def uniquePerms(self, arr, n):
        # code here 

        return sorted(set(permutations(arr)))





def main():
    arr = [1,2,1]
    solution = Solution()
    ans = solution.uniquePerms(arr, len(arr))
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
