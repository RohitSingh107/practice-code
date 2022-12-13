from collections import deque
from typing import List, Deque


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:

        m = len(graph)
        revGraph = [[] for _ in range(m)]
        indegree = [0 for _ in range(m)] 

        for i in range(m):
            for n in graph[i]:
                revGraph[n].append(i)
                indegree[i] += 1

        q = deque([i for i in range(m) if indegree[i] == 0])

        result = []

        while len(q) != 0:
            v = q.popleft()

            for n in revGraph[v]:
                indegree[n] -= 1
                if indegree[n] == 0:
                    q.append(n)
            result.append(v)

        return result















def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
