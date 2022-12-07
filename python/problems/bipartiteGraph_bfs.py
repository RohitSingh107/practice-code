from typing import List, Tuple

def bfs(v : int, adj : List[List[int]], colors: List[int]) -> bool:
    ans = True

    q : List[Tuple[int,int]] = []
    q.append((v,0))

    colors[v] = 0

    while not q == []:
        (n, nc) = q[0]
        q.pop(0)

        for ch in adj[n]:
            if colors[ch] == -1:
                q.append((ch, not nc))
                colors[ch] = (not nc)
            else:
                if colors[ch] == nc:
                    return False


    return ans

def isBipartite(V : int, adj : List[List[int]]) -> bool:

    ans = True

    colors = [-1 for _ in range(V)]

    for i in range(V):
        if colors[i] == -1:
            ans = ans and bfs(i,adj,colors)
    
    return ans



    


