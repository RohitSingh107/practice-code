# https://leetcode.com/problems/delete-node-in-a-linked-list/
from collections import deque
from typing import List, Deque


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteNode(self, node : ListNode):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """

        prv = node
        while node.next is not None:

            node.val = node.next.val
            prv = node
            node = node.next
        prv.next = None











def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
