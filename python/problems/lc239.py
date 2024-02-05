# https://leetcode.com/problems/sliding-window-maximum/description/
from pprint import pprint
from typing import List, Deque
from collections import deque




class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        ans : Deque[int] = deque()

        d : Deque[int] = deque()
        # d.append(nums[0])

        for i in range(0, k):
            while len(d) > 0 and nums[d[-1]] <= nums[i]:
                d.pop()
            d.append(i)

        ans.append(nums[d[0]])
        print(d, list(map(lambda x : nums[x], d)))

        for i in range(k, len(nums)):
            if d[0] < i - k + 1:
                d.popleft()

            while len(d) > 0 and nums[d[-1]] <= nums[i]:
                d.pop()
            d.append(i)
            ans.append(nums[d[0]])

        return list(ans)








def main():
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    solution = Solution()
    ans = solution.maxSlidingWindow(nums,k)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
