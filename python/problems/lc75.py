from collections import deque
from typing import List, Deque







class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        f = 0
        l = len(nums) -1

        while f <= l and nums[f] == 0:
            f += 1

        while l >= 0 and nums[l] == 2:
            l -= 1

        if f >= l:
            return

        # print("f is ", f)
        i = f
        while True:
            if i > l or i < 0:
                break
            # print(f"i is {i}, l is {l}")
            # print("h1")
            if nums[i] == 0:
                # print("h1")
                if f > i:
                    i += 1
                    continue
                # print(f"f nums is {nums}, swapping index {f}, and {i}. ", end = "")
                nums[f], nums[i] = nums[i], nums[f]
                # print(f"f nums is {nums}, swaped index {f}, and {i}")
                f += 1
                # i -= 1
                continue
            if nums[i] == 2:
                if i > l:
                    break
                # print(f"l nums is {nums}, swapping index {i}, and {l}. ", end = "")
                nums[l], nums[i] = nums[i], nums[l]
                # print(f"l nums is {nums}, swaped index {i}, and {l}")
                l -= 1
                # i -= 1
                continue
            i += 1

            # print(f"i is {i}, l is {l}")
        # print(nums)







def main():
    # nums = [2,0,2,1,1,0]
    # nums = [2,0,1]
    # nums = [0, 0]
    nums = [1,2,0]
    solution = Solution()
    print(f"ans is {solution.sortColors(nums)}")

if __name__ == '__main__':
    main()
