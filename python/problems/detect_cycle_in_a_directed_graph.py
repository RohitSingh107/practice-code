# https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

from typing import List
from collections import deque

def isCyclic( V, adj) -> bool:

    # Topological Sort
    indegree = [0 for _ in range(V)]

    for i in range(V):
        for n in adj[i]:
            indegree[n] += 1

    q = deque([])

    for i in range(V):
        if indegree[i] == 0:
            q.append(i)
    res = []
    while len(q) != 0:
        v = q.popleft()
        
        for n in adj[v]:
            indegree[n] -= 1
            if indegree[n] == 0:
                q.append(n)
        res.append(v) 

    print(res)

    return bool(len(res) != V)
    


def main():
    print(isCyclic(3, [[1], [2], []]))
    pass

if __name__ == "__main__":
    main()
