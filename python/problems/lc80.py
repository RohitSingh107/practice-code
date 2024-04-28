
from pprint import pprint
from typing import List, Deque
from collections import deque






class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        a = 0

        previous_element = float('inf')
        pec = 0

        for i in range(len(nums)):
            if nums[i] == previous_element:
                pec += 1
            else:
                pec = 1

            previous_element = nums[i]

            if pec <= 2:
                nums[a] = nums[i]
                a += 1

        return a








def main():
    # nums = [1,1,1,2,2,3]
    nums = [0,0,1,1,1,1,2,3,3]

    solution = Solution()
    ans = solution.removeDuplicates(nums)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
