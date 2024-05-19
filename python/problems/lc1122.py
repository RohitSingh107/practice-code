# https://leetcode.com/problems/relative-sort-array/description/
from pprint import pprint
from typing import List, Deque
from collections import deque, OrderedDict, defaultdict






class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:

        ans = deque()

        d = defaultdict(int)

        for n in arr1:
            d[n] += 1

        for n in arr2:
            if n in d:
                ans.extend([n] * d[n])
                d.pop(n)


        for n in sorted(d):
            ans.extend([n] * d[n])


        return list(ans)






def main():
    arr1 = [2,3,1,3,2,4,6,7,9,2,19]
    arr2 = [2,1,4,3,9,6]

    solution = Solution()
    ans = solution.relativeSortArray(arr1, arr2)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
