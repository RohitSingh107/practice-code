# https://leetcode.com/problems/sort-an-array/
from collections import deque
from typing import List, Deque


def insertion_sort(nums: List[int]) -> List[int]:

    n = len(nums)

    for i in range(1, n):
        j = i
        while j > 0 and nums[j-1] > nums[j]:
            nums[j], nums[j-1] = nums[j-1], nums[j]
            j -= 1
    return nums


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        return insertion_sort(nums)


def main():
    nums = [5, 2, 3, 1]
    solution = Solution()
    print(f"ans is {solution.sortArray(nums)}")


if __name__ == '__main__':
    main()
