# https://practice.geeksforgeeks.org/problems/course-schedule/1

from typing import List, Deque
from collections import defaultdict, deque


# def findOrder(N, m, prerequisites):
#
#     adj = [[] for _ in range(N)]
#     for p in prerequisites:
#         adj[p[1]].append(p[0])
#
#     print(adj)
#
#     indegree = [0 for _ in range(N)]
#
#     for i in range(N):
#         for n in adj[i]:
#             indegree[n] += 1
#     print(indegree)
#
#     q: Deque = deque([])
#
#     for i in range(N):
#         if indegree[i] == 0:
#             print("pushing {i}")
#             q.append(i)
#             # visited[i] = True
#
#     result = []
#     while len(q) != 0:
#
#         v = q.popleft()
#         for n in adj[v]:
#             indegree[n] -= 1
#             if indegree[n] == 0:
#                 q.append(n)
#             # if not visited[n]:
#             #     q.append(n)
#             #     visited[n] = True
#
#         result.append(v)
#
#     print(result)
#
#     if len(result) == N:
#         return result
#
#     return []

class Solution:
    def findOrder(self, n : int, m : int, prerequisites : List[List[int]]) -> List[int]:
        # Code here

        graph = defaultdict(Deque[int])
        indegree = defaultdict(int)

        for p in prerequisites:
            graph[p[1]].append(p[0])
            indegree[p[0]] += 1


        q : Deque[int] = deque()

        for i in range(n):
            if not indegree[i]:
                q.append(i)

        ans = deque()

        while len(q):
            v = q.popleft()
            ans.append(v)

            for c in graph[v]:
                indegree[c] -= 1
                if indegree[c] == 0:
                    q.append(c)


        if len(ans) != n:
            return []

        return list(ans)

def main():

    # n= 8
    # m= 10
    # p = [[4, 1], [7, 1], [1, 2], [2, 5], [1, 0], [2, 0], [5, 0], [7, 3], [5, 3], [0, 6]]

    # n= 4
    # m= 4
    # p = [[1,0],[2,0],[3,1],[3,2]]

    n = 2
    m = 1
    p = [[1,0]]

    solution = Solution()
    print(solution.findOrder(n, m, p))


if __name__ == "__main__":
    main()


