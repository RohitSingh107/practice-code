from collections import deque
from typing import List, Deque, Tuple
from icecream import ic
import heapq


class Solution:
    # Function to find the shortest distance of all the vertices
    # from the source vertex S.
    def dijkstra(self, V: int, adj: List[List[List[int]]], S: int):
        # code here

        distances = [float('infinity')] * V
        distances[S] = 0

        pq: List[Tuple[int, int]] = [(0, S)]

        while pq:
            cost, node = heapq.heappop(pq)

            if cost > distances[node]:
                continue

            for child, weight in adj[node]:
                if cost + weight < distances[child]:
                    distances[child] = cost + weight
                    heapq.heappush(pq, (cost + weight, child))

        return distances


def main():
    # adj = [[[1, 9]], [[0, 9]]]
    adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]]
    solution = Solution()
    print(f"ans is {solution.dijkstra(3, adj, 2)}")


if __name__ == '__main__':
    main()
