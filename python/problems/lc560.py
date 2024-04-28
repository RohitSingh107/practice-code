
from pprint import pprint
from typing import List, Deque
from collections import deque, defaultdict




class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        occ = defaultdict(int)
        occ[0] = 1

        ans = 0
        prefix = 0

        for i in nums:
            prefix += i

            required = prefix - k
            ans += occ[required]
            occ[prefix] += 1

        return ans








def main():
    nums = [1,2,3,-3,1,1,1,4,2,-3]
    k = 3

    # nums = [1,1,1]
    # k = 2
    
    # nums = [1,2,3]
    # k = 3

    # nums = [1]
    # k = 0

    solution = Solution()
    ans = solution.subarraySum(nums, k)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
