# https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

from typing import List, Deque
from collections import deque

def isPossible(N,prerequisites):
    adj = [[] for _ in range(N)]
    for p in prerequisites:
        adj[p[0]].append(p[1])

    indegree= [0 for _ in range(N)]

    for i in range(N):
        for n in adj[i]:
            indegree[n] += 1
    print(indegree)

    q : Deque = deque([])

    for i in range(N):
        if indegree[i] == 0:
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

    return bool(len(result) == N)

def main():
    pass

if __name__ == "__main__":
    main()
