from collections import deque
from typing import List, Deque





# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
        


def dfs(root : Node | None, sum : int, acc : int, path : Deque[int], paths : Deque[List[int]]):

    if root is None:
        return

    # print("node is ", root.data, " acc is", acc, "path is ", path)

    path.append(root.data)
    if acc + root.data == sum:
        # print(*path)
        paths.append(list(path.copy()))
    dfs(root.left, sum, acc + root.data, path, paths)

    dfs(root.right, sum, acc + root.data, path, paths)

    path.pop()

class Solution:
    def printPaths(self, root, sum):
        #code here
        path = deque()

        paths = deque()

        dfs(root, sum, 0, path, paths)

        return paths









def main():

    sum = 38
    root = Node(10)
    root.left = Node(28)
    root.right = Node(13)
    root.right.left = Node(4)
    root.right.left.left = Node(6)
    root.right.left.right = Node(7)
    root.right.right = Node(15)
    root.right.right.left = Node(8)
    root.right.right.right = Node(9)


    solution = Solution()
    print(f"ans is {solution.printPaths(root, sum)}")

if __name__ == '__main__':
    main()
