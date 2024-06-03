# https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
from collections import deque
from typing import List, Deque


class Solution:
    # Function to construct and return cost of MST for a graph
    # represented using adjacency matrix representation
    '''
    V: nodes in graph
    edges: adjacency list for the graph
    S: Source
    '''

    def bellman_ford(self, V: int, edges: List[List[int]], S: int):
        # code here

        distances = [float('inf')]*V
        distances[S] = 0

        for _ in range(V - 1):
            for v1, v2, w in edges:

                if distances[v1] + w < distances[v2]:
                    distances[v2] = distances[v1] + w

        for v1, v2, w in edges:
            if distances[v1] + w < distances[v2]:
                return [-1]

        return list(map(lambda x: 10**8 if x == float('inf') else x, distances))


def main():
    V = 3
    e = [[0, 1, 5], [1, 0, 3], [1, 2, -1], [2, 0, 1]]
    S = 2
    solution = Solution()
    print(f"ans is {solution.bellman_ford(V, e, S)}")


if __name__ == '__main__':
    main()
