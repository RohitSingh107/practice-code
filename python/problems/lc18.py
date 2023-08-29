# https://leetcode.com/problems/4sum/

from collections import deque
from typing import List, Deque


class Solution:
    # def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
    #     
    #     s = set()
    #
    #     n = len(nums)
    #
    #     ans = set()
    #
    #     for i in range(n):
    #         for j in range(i+1, n):
    #             s.clear()
    #             for k in range(j+1, n):
    #                 rq = target - (nums[i] + nums[j] + nums[k])
    #
    #                 if rq in s:
    #                     ans.add(tuple(sorted([nums[i], nums[j], nums[k], rq])))
    #                 else:
    #                     s.add(nums[k])
    #     return list(ans)
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        n = len(nums)

        ans = deque()
        
        nums = sorted(nums)

        for i in range(n):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, n):
                if j > i + 1 and nums[j] == nums[j-1]:
                    continue
                k = j + 1
                l = n -1

                while k < l:
                    if nums[i] + nums[j] + nums[k] + nums[l] < target:
                        k += 1
                        # while k < l and nums[k] == nums[k-1]:
                        #     k += 1
                    elif nums[i] + nums[j] + nums[k] + nums[l] > target: 
                        l -= 1
                        # while k < l and nums[l] == nums[l+1]:
                        #     l -= 1
                    else:
                        # print(f"target is {target}")
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k +=1
                        l -= 1

                        while k < l and nums[k] == nums[k-1]:
                            k += 1
                        while k < l and nums[l] == nums[l+1]:
                            l -= 1


        return list(ans)














def main():
    # nums = [1,0,-1,0,-2,2]
    # target = 0 
    nums = [2,2,2,2,2]
    target = 8

    solution = Solution()
    print(f"ans is {solution.fourSum(nums, target)}")

if __name__ == '__main__':
    main()
