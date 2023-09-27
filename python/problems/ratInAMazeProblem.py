
from typing import List, Deque
from collections import deque
from pprint import pprint




def f(i : int, j : int, n : int, m : List[List[int]], ds : Deque[str], all_paths : Deque[str], visited : List[List[bool]]):
    # print(f"here i is {i}, j is {j}")
    # print("here", i, j)
    # print(f"{i=}, {j=}")

    if i == n - 1 == j:
        all_paths.append("".join(ds))
        return

    if m[i][j] == 0:
        return

    visited[i][j] = True

    if i > 0 and m[i-1][j] == 1 and not visited[i-1][j]:
        ds.append('U')
        f(i-1, j, n, m, ds, all_paths, visited)
        visited[i-1][j] = False
        ds.pop()
    if i + 1 < n and m[i+1][j] == 1 and not visited[i+1][j]:
        ds.append('D')
        f(i+1, j, n, m, ds, all_paths, visited)
        visited[i+1][j] = False
        ds.pop()
    if j > 0 and m[i][j-1] == 1 and not visited[i][j-1]:
        ds.append('L')
        f(i, j-1, n, m, ds, all_paths, visited)
        visited[i][j-1] = False
        ds.pop()
    if j + 1 < n and m[i][j+1] == 1 and not visited[i][j+1]:
        ds.append('R')
        f(i, j+1, n, m, ds, all_paths, visited)
        visited[i][j+1] = False
        ds.pop()



class Solution:
    def findPath(self, m, n):
        # code here

        ds = deque()
        all_paths = deque()
        visited = [[False for _ in range(n)] for _ in range(n)]
        print("here")
        f(0, 0, n, m, ds, all_paths , visited)
        # return list(map("".join, all_paths))
        return all_paths





def main():
    m = [[1,0,0,0], [1,1,0,1], [1,1,0,0], [0,1,1,1]]
    solution = Solution()
    ans = solution.findPath(m, len(m))
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
