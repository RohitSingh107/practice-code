from collections import deque
from typing import List, Deque


class Solution:
    def maxLen(self, n, arr):

        k = 0

        ans = 0
        d = {}
        d[0] = -1
        prefix_sum = 0
        for i in range(n):
            prefix_sum += arr[i]
            remaining = prefix_sum - k
            # print(f"i is {i}, prefix_sum is {prefix_sum}, remaining is {remaining}")
            if remaining in d:
                l = i - d[remaining]
                # print(f"i is {i}, prefix_sum is {prefix_sum}, l is {l}, d is {d}")
                ans = max(ans, l)
                # continue
            if prefix_sum not in d:
                d[prefix_sum] = i
        return ans













def main():
    n = 8
    arr = [15,-2,2,-8,1,7,10,23]
    # n = 4
    # arr = [-1,1,-1,1]
    solution = Solution()
    print(f"ans is {solution.maxLen(n, arr)}")

if __name__ == '__main__':
    main()
