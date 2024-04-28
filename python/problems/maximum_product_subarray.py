
from pprint import pprint
from typing import List, Deque
from collections import deque






class Solution:
    def maxProduct(self,arr, n):

        ans = -float('inf')

        prefix = 1
        sufix = 1

        for i in arr:
            prefix *= i
            ans = max(ans, prefix)

            if prefix == 0:
                prefix = 1

        for i in arr[::-1]:
            sufix *= i
            ans = max(ans, sufix)

            if sufix == 0:
                sufix = 1
        return ans







def main():
    # arr = [6, -3, -10, 0, 2]
    arr = [2, 3, 4, 5, -1, 0]
    solution = Solution()
    ans = solution.maxProduct(arr, len(arr))
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
