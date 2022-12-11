# https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
from typing import List, Deque
from collections import deque

def eventualSafeNodes(self, V : int, adj : List[List[int]]) -> List[int]:

    adjRev = [[] for _ in range(V)]
    indegree = [0 for _ in range(V)]
    for i in range(V):
        for n in adj[i]:
            adjRev[n].append(i)
            indegree[i] += 1

    result = []
    
    q : Deque = deque([])
    for i in range(V):
        if indegree[i] == 0:
            q.append(i)

    while len(q) != 0:
        v = q.popleft()
        for n in adjRev[v]:
            indegree[n] -= 1
            if indegree[n] == 0:
                q.append(n)
        result.append(v)

    return result
            


def main():
    pass

if __name__ == "__main__":
    main()
