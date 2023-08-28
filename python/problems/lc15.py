# https://leetcode.com/problems/3sum/
from collections import deque
from typing import List, Deque, Tuple







# class Solution:
#     def threeSum(self, nums: List[int]) -> List[Tuple[int]]:
#
#         s = set()
#         ans = set()
#         n = len(nums)
#         for i in range(n):
#             s.clear()
#             for j in range(i+1, n):
#                 rq = -1 * (nums[i] + nums[j])
#                 if rq in s:
#                     ans.add(tuple(sorted((nums[i], nums[j], rq))))
#                 else:
#                     s.add(nums[j])
#
#         return list(ans)

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:


        ans = set()

        nums = sorted(nums)
        
        n = len(nums)
        for i in range(n):

            if i > 0 and nums[i] == nums[i-1]:
                continue

            j = i +1
            k = n -1
            while j < k:
                if nums[i] + nums[j] + nums[k] < 0:
                    j += 1
                elif nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                else:
                    ans.add((nums[i], nums[j], nums[k]))

                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1

                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -=1

        return list(map(lambda x : list(x), list(ans)))










def main():
    nums = [-1,0,1,2,-1,-4]

    solution = Solution()
    print(f"ans is {solution.threeSum(nums)}")

if __name__ == '__main__':
    main()
