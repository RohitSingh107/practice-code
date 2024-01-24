from collections import deque
from typing import List, Deque





def dfs(n : int, p : int, graph : List[Deque[int]], visited : List[bool]) -> bool:


    visited[n] = True

    ans = True


    for c in graph[n]:
        if c == p:
            continue
        if visited[c]:
            # print("here n is ", n, ", c is ", c, "visited is ", visited)
            return False
        ans = ans and dfs(c, n, graph, visited)

        if not ans:
            return False

    return ans




# https://www.geeksforgeeks.org/problems/is-it-a-tree/1
class Solution:
    def isTree(self, n : int, m : int, edges : List[List[int]]) -> int:
        # Code here

        if n != m + 1:
            return 0

        graph : List[Deque[int]] = [deque() for _ in range(n)]

        for v1, v2 in edges:
            graph[v1].append(v2)
            graph[v2].append(v1)

        visited = [False] * n

        return int(dfs(0, -1, graph, visited) and all(visited))

  



def main():
    N = 4
    M = 3
    G = [[0, 1], [1, 2], [1, 3]]
    # G = [[0, 1], [1, 2], [2, 0]]

    solution = Solution()
    print(f"ans is {solution.isTree(N,M,G)}")

if __name__ == '__main__':
    main()
