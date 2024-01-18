from collections import deque
from typing import List, Deque, Tuple






class Solution:
    def min_sprinklers(self, gallery : List[int], n : int):
        # code here
        ranges : Deque[Tuple[int,int]] = deque()
        for i,x in enumerate(gallery):
            if x == -1:
                continue

            l = i - x
            r = i + x
            ranges.append((l if l >= 0 else 0,r if r < n else n-1))

        sorted_ranges = sorted(ranges)

        target = 0
        tap = 0
        i = 0

        while target < n:

            max_reach = -1

            while i < len(sorted_ranges):
                if sorted_ranges[i][0] <= target:
                    max_reach = max(max_reach,sorted_ranges[i][1])
                    i += 1
                else:
                    break

            if max_reach < target:
                return -1

            tap += 1
            target = max_reach + 1


        return tap













def main():


    n = 6
    gallery = [-1, 2, 2, -1, 0, 0]
    solution = Solution()
    print(f"ans is {solution.min_sprinklers(gallery, n)}")

if __name__ == '__main__':
    main()
