# https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
from collections import deque
from typing import List, Deque, Set, Tuple

import heapq


class Solution:
    def maxCombinations(self, N: int, K: int, A: List[int], B: List[int]) -> List[int]:
        # Code here

        heap: List[Tuple[int, Tuple[int, int]]] = []

        ans: Deque[int] = deque()

        used : Set[Tuple[int, int]] = set()

        A.sort()
        B.sort()

        heapq.heappush(heap, (-1 * (A[N - 1] + B[N - 1]), (N-1, N-1)))

        while len(ans) < K:
            # print("heap is ", heap)
            mx, (a, b) = heapq.heappop(heap)
            ans.append(-1 * mx)

            if a >= 1 and (a-1, b) not in used:
                used.add((a-1, b))
                heapq.heappush(heap, (-1 * (A[a-1] + B[b]), (a - 1, b)))

            if b >= 1 and (a, b-1) not in used:
                used.add((a, b-1))
                heapq.heappush(heap, (-1 * (A[a] + B[b - 1]), (a, b - 1)))

        return list(ans)


def main():


    # N = 4
    # K = 3
    # A  = [1, 4, 2, 3]
    # B  = [2, 5, 1, 6]

    N = 2
    K = 2
    A   = [3, 2]
    B  = [1, 4]

    solution = Solution()
    print(f"ans is {solution.maxCombinations(N,K,A, B)}")


if __name__ == "__main__":
    main()
