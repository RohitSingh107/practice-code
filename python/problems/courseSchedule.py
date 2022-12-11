# https://practice.geeksforgeeks.org/problems/course-schedule/1

from typing import List, Deque
from collections import deque


def findOrder(N, m, prerequisites):

    adj = [[] for _ in range(N)]
    for p in prerequisites:
        adj[p[1]].append(p[0])

    print(adj)

    indegree = [0 for _ in range(N)]

    for i in range(N):
        for n in adj[i]:
            indegree[n] += 1
    print(indegree)

    q: Deque = deque([])

    for i in range(N):
        if indegree[i] == 0:
            print("pushing {i}")
            q.append(i)
            # visited[i] = True

    result = []
    while len(q) != 0:

        v = q.popleft()
        for n in adj[v]:
            indegree[n] -= 1
            if indegree[n] == 0:
                q.append(n)
            # if not visited[n]:
            #     q.append(n)
            #     visited[n] = True

        result.append(v)

    print(result)

    if len(result) == N:
        return result

    return []


def main():
    p = [[4, 1], [7, 1], [1, 2], [2, 5], [1, 0], [2, 0], [5, 0], [7, 3], [5, 3], [0, 6]]
    print(findOrder(8, 10, p))


if __name__ == "__main__":
    main()


