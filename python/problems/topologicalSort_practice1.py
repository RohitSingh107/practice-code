# https://www.geeksforgeeks.org/problems/topological-sort/1
from collections import deque
from typing import List, Deque



def dfs(n, adj, visited, stack):
    
    visited[n] = True

    for child in adj[n]:
        if not visited[child]:
            dfs(child, adj, visited, stack)

    stack.appendleft(n)




class Solution:
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        # Code here
        visited = [False] * V
        stack = deque()

        for i in range(V):
            if not visited[i]:
                dfs(i, adj, visited, stack)

        return list(stack)


def main():
    adj = [[], [0], [0], [0]]
    solution = Solution()
    print(f"ans is {solution.topoSort(len(adj), adj)}")

if __name__ == '__main__':
    main()
