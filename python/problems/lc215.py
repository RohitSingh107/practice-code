# https://leetcode.com/problems/kth-largest-element-in-an-array/description/
from collections import deque
from typing import List, Deque
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        heap : List[int] = []
        for n in nums:
            if len(heap) < k:
                heapq.heappush(heap, n)
            else:
                if heap[0] < n:
                    heapq.heapreplace(heap, n)

        print(heap)
        return heap[0]
        












def main():
    # nums = [3,2,1,5,6,4]
    # k = 2
    
    nums = [3,2,3,1,2,4,5,5,6]
    k = 4

    solution = Solution()
    print(f"ans is {solution.findKthLargest(nums, k)}")

if __name__ == '__main__':
    main()
