from typing import List

def dfs(v : int, c: int, adj : List[List[int]], colors: List[int]) -> bool:

    if colors[v] != -1:
        if colors[v] != c:
            return False
        else:
            return True

    colors[v] = c

    ans = True;

    for n in adj[v]:
        ans = ans and dfs(n, not c, adj, colors) 
        

    return ans

def isBipartite(V : int, adj : List[List[int]]) -> bool:
    colors = [-1 for _ in range(V)]

    ans = True
    for i in range(V):
        if colors[i] == -1:
            ans = ans and dfs(i, 0, adj, colors)
    return ans

