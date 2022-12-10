
from typing import List, Deque
from collections import deque

def dfs(v : int, graph : List[List[int]], visited : List[bool], container: Deque[int]):
    visited[v] = True

    for n in graph[v]:
        if not visited[n]:
            dfs(n, graph, visited, container)
    
    container.appendleft(v)


def topoSortDFS( V, adj) -> List[int]:

    visited = [False for _ in range(V)]

    container : Deque = deque([])

    for i in range(V):
        if not visited[i]:
            dfs(i, adj, visited, container)
    ans = list(container)
    return ans

def topoSortBFS( V, adj) -> List[int]:

    # visited = [False for _ in range(V)]
    indegree= [0 for _ in range(V)]

    for i in range(V):
        for n in adj[i]:
            indegree[n] += 1
    print(indegree)

    q : Deque = deque([])

    for i in range(V):
        if indegree[i] == 0:
            print("appending")
            q.append(i)
            # visited[i] = True

    print(q)
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

    return result
        
        

def main():
    graph : List[List[int]] = [[], [], [3], [1], [0,1], [0,2]]
    # graph : List[List[int]] = [[], [3], [3], [], [0,1], [0,2]]
    # graph : List[List[int]] = [[], [0], [0], [0]]
    # print(topoSortDFS(len(graph), graph))
    print(topoSortBFS(len(graph), graph))


if __name__ == '__main__':
    main()
