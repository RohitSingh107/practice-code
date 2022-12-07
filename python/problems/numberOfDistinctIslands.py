# https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

from typing import List, Tuple, Set

def dfs(i : int, j: int, bx :int, by: int, grid : List[List[int]], visited : List[List[bool]], store : List[Tuple[int,int]] ):

    if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or visited[i][j] or grid[i][j] != 1:
        return

    visited[i][j] = True
    store.append((i - bx,j- by))

    dfs(i-1,j, bx, by, grid, visited, store)
    dfs(i,j+1, bx, by, grid, visited, store)
    dfs(i,j-1, bx, by, grid, visited, store)
    dfs(i+1,j, bx, by, grid, visited, store)

def countDistinctIslands(grid : List[List[int]]) -> int:

    m = len(grid)
    n = len(grid[0])


    visited = [[False for _ in range(n)] for _ in range(m)]

    # s : Set[List[Tuple[int,int]]] = set()
    s = set()


    for i in range(m):
        for j in range(n):
            if not visited[i][j] and grid[i][j] == 1:
                store : List[Tuple[int,int]] = []
                dfs(i,j, i, j,grid,visited, store)
                s.add(tuple(store))
    return len(s)

grid =      [[1, 1, 0, 1, 1],
            [1, 0, 0, 0, 0],
            [0, 0, 0, 0, 1],
            [1, 1, 0, 1, 1]]

print(countDistinctIslands(grid))
