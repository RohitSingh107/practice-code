# https://leetcode.com/problems/top-k-frequent-elements/description/
from collections import deque, Counter
from typing import List, Deque








class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = Counter(nums)
        return list(map(lambda x: x[0], c.most_common(k)))





def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
