# https://leetcode.com/problems/largest-rectangle-in-histogram/
from collections import deque
from typing import List, Deque


import sys


# class Solution:
#     def largestRectangleArea(self, heights: List[int]) -> int:
#
#         n = len(heights)
#         ans = -sys.maxsize
#
#         for i in range(n):
#
#             l = i
#             while l > -1 and heights[l] >= heights[i]:
#                 l -= 1
#
#             r = i
#             while r < n and heights[r] >= heights[i]:
#                 r += 1
#
#             ans = max(ans, heights[i] * (r - l - 1))
#             print("ans is ", ans, ", i is ", i, ", l is ", l, ", r is ", r)
#
#         return ans


# class Solution:
#     def largestRectangleArea(self, heights: List[int]) -> int:
#
#         ans = -sys.maxsize
#
#         n = len(heights)
#
#         next_smallers = [n] * n
#
#         stack : Deque[int] = deque()
#
#         for i in range(n):
#             while len(stack) > 0 and heights[stack[-1]] >= heights[i]:
#                 x = stack.pop()
#                 next_smallers[x] = i
#             stack.append(i)
#
#         previous_smallers = [-1] * n
#         stack.clear()
#         for i in range(n):
#             while len(stack) > 0 and heights[stack[-1]] >= heights[i]:
#                 x = stack.pop()
#             if len(stack) > 0:
#                 previous_smallers[i] = stack[-1]
#             stack.append(i)
#
#         for i in range(n):
#             ans = max(ans, heights[i] * (next_smallers[i] - previous_smallers[i] - 1))
#
#         # print(previous_smallers, stack)
#
#         return ans


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = -sys.maxsize

        n = len(heights)

        stack: Deque[int] = deque()

        for r in range(n + 1):
            while len(stack) > 0 and (r == n or heights[stack[-1]] > heights[r]):
                h = heights[stack.pop()]
                l = -1 if len(stack) == 0 else stack[-1]
                ans = max(ans, h * (r - l - 1))

            stack.append(r)

        return ans


def main():
    # heights = [2,1,5,6,2,3]
    # heights = [1]
    heights = [2, 4]

    solution = Solution()
    print(f"ans is {solution.largestRectangleArea(heights)}")


if __name__ == "__main__":
    main()
