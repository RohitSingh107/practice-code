# https://leetcode.com/problems/next-greater-element-i/description/
from collections import deque
from typing import List, Deque






class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:

        mystack : Deque[int] = deque()
        d = {}

        for n in nums2[::-1]:
 
            while len(mystack) > 0 and n >= mystack[0]:
                mystack.popleft()

            if not mystack:
                d[n] = -1
                mystack.appendleft(n)
            else:
                d[n] = mystack[0]
                mystack.appendleft(n)
        return [d[n] for n in nums1]







def main():
    # nums1 = [4,1,2]
    # nums2 = [1,3,4,2]

    nums1 = [2,4]
    nums2 = [1,2,3,4]

    solution = Solution()
    print(f"ans is {solution.nextGreaterElement(nums1, nums2)}")

if __name__ == '__main__':
    main()
