# https://leetcode.com/problems/sort-an-array/
from collections import deque
from typing import List, Deque


def bubble_sort(nums: List[int]) -> List[int]:

    n = len(nums)

    for i in range(n-2, -1, -1):
        swapped = False
        for j in range(i+1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                swapped = True
        if not swapped:
            break

    return nums


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        return bubble_sort(nums)


def main():
    nums = [5, 2, 3, 1]
    solution = Solution()
    print(f"ans is {solution.sortArray(nums)}")


if __name__ == '__main__':
    main()
