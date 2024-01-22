

from typing import List
import copy

import sys

def minOperations(i : int, n, m : int, arr : List[int], org: List[int], check : bool) -> int:

    if i == n:

        if check:
            return 0
        else:
            return sys.maxsize


    # modify
    modify = sys.maxsize
    o = arr[i]
    arr[i] = (arr[i] + 1) % m
    if arr[i] != org[i]:
        if check and (arr[i] >= arr[i-1] or i == 0):
            check = True
        else:
            check = False
        modify = minOperations(i, n, m, arr, org, check) + 1
    arr[i] = o

    if check and (arr[i] >= arr[i-1] or i == 0):
        check = True
    else:
        check = False
    # not modify
    not_modify = minOperations(i + 1, n, m, arr, org, check) + 0

    return min(modify, not_modify)


class Solution:
    def minOperations(self, n : int, m : int, arr : List[int]) -> int:
        # code here
        if n < 2:
            return 0
        org = copy.deepcopy(arr)
        return minOperations(0, n, m, arr, org, True)









def main():

    # n = 4
    # m = 5
    # arr = [4,1,3,2]

    # n = 5
    # m = 10
    # arr = [0,0,1,3,7]

    n = 6
    m = 9
    arr = [5,2,1,4,5,4]

    solution = Solution()
    print(f"ans is {solution.minOperations(n,m,arr)}")

if __name__ == '__main__':
    main()

# 6
# 9
# 5 2 1 4 5 4
