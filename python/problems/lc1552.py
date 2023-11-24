# https://leetcode.com/problems/magnetic-force-between-two-balls/description/
from collections import deque
from typing import List, Deque




def possible(mid : int, m : int, position : List[int]) -> bool:

    balls = 1
    last_placed = position[0]

    for p in position[1:]:
        if p - last_placed >= mid:
            balls += 1
            last_placed = p

            if balls >= m:
                return True

    return False




class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:

        position.sort()

        lo = 1
        hi = position[-1] - position[0]

        while lo <= hi:
            mid = (lo + hi) // 2

            if possible(mid, m, position):
                lo = mid + 1
            else:
                hi = mid - 1

        return hi









def main():
    # position = [1,2,3,4,7]
    # m = 3

    position = [5,4,3,2,1,1000000000]
    m = 2
    solution = Solution()
    print(f"ans is {solution.maxDistance(position, m)}")

if __name__ == '__main__':
    main()
