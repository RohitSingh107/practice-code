# https://leetcode.com/problems/two-sum/
from collections import deque
from typing import List, Deque

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        # d = {}
        # for i, num in enumerate(nums):
        #     rq = target - num
        #     if rq in d:
        #         return [i, d[rq]]
        #     else:
        #         d[num] = i

        enums = enumerate(nums)

        enums = sorted(enums, key= lambda x : x[1])
        # print(enums)

        i = 0
        j = len(nums) -1

        while i < j:
            t = enums[i][1] + enums[j][1]
            if t < target:
                i += 1
            elif t > target:
                j -= 1
            else:
                # print(f"i is {i}, j is {j}, enumsi is {enums[i]}, enumsj is {enums[j]}")
                return [enums[i][0], enums[j][0]]















def main():
    nums = [2,7,11,15]
    target = 9

    # nums = [3,2,4]
    # target = 6

    nums = [3,2,3]
    target = 6

    solution = Solution()
    print(f"ans is {solution.twoSum(nums, target)}")

if __name__ == '__main__':
    main()
