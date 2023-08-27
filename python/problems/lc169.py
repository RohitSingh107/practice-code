# https://leetcode.com/problems/majority-element/

from typing import List

def majorityElement(nums: List[int]) -> int:

    cnt = 0
    ans = nums[0]
    for i in nums:
        if cnt == 0:
            ans = i
            cnt = 1
        else:
            if i == ans:
                cnt += 1
            else:
                cnt -= 1
    return ans



# nums = [2,2,1,1,1,2,2]
nums = [3,2,3]
print(majorityElement(nums))
