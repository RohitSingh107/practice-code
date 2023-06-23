from collections import deque
from typing import List, Deque
import itertools as it








def next_permutation(nums : List[int]):
    l = len(nums)

    bp = -1

    for i in range(l-2, -1, -1):
        if nums[i] < nums[i+1]:
            bp = i
            break
    # print("bp is ", bp)
    if bp == -1:
        nums.reverse()
        return

    for i in range(l-1, bp, -1):
        if nums[i] > nums[bp]:
            nums[bp], nums[i] = nums[i], nums[bp]
            break
    print("here num is ", nums)


    for i in range(bp +1, bp + (( l - 1 - bp) // 2) + 1):
        nums[i], nums[l -1 -i + bp + 1] = nums[l -1 -i + bp + 1], nums[i]











class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        next_permutation(nums)


def main():
    nums = [1,2,3]
    # nums = [3,2,1]
    # nums = [1,1,5]
    # nums = [2,1,5,4,3,0,0]
    # nums = [1,3,2]
    solution = Solution()
    print(f"ans is {solution.nextPermutation(nums)}")
    print(nums)

if __name__ == '__main__':
    main()
