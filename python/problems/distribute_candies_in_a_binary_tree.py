# https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1
from collections import deque
from typing import List, Deque, Tuple









class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

class Solution:

    def distributeCandy(self, root : Node | None) -> int:
        #code here

        def solve(root : Node | None) -> Tuple[int,int]:
            if root is None:
                return (0,0)


            # req = root.data + solve(root.left) + solve(root.right) - 1
            lr = solve(root.left)
            rr = solve(root.right)
            req = root.data + lr[0] + rr[0] - 1
            ans = rr[1] + lr[1] + abs(req)
            # print(f"lr is {lr}, n is {root.data}, rr is {rr}, req is {req}, ans is {self.ans}")

            return (req, ans)

        ans = solve(root)
        # print("one is ", one)

        return ans[0] + ans[1]





def main():

    root = Node(3)
    root.left = Node(0)
    root.right = Node(0)

    # root = Node(0)



    solution = Solution()
    print(f"ans is {solution.distributeCandy(root)}")

if __name__ == '__main__':
    main()
