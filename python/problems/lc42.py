from collections import deque
from typing import List, Deque





# https://leetcode.com/problems/trapping-rain-water/
class Solution:
    def trap(self, height: List[int]) -> int:

        water = 0

        leftMax = 0
        rightMax = 0
        i = 0
        j = len(height) -1

        while i < j:
            if leftMax < height[i]:
                leftMax = height[i]

            if leftMax > rightMax:
                while i < j:
                    if height[j] > rightMax:
                        rightMax = height[j]
                        if leftMax < rightMax:
                            break
                    water += (rightMax - height[j])
                    j -= 1
            water += (leftMax - height[i])
            i += 1


        return water



def main():
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    # height = [4,2,0,3,2,5]
    solution = Solution()
    print(f"ans is {solution.trap(height=height)}")

if __name__ == '__main__':
    main()
