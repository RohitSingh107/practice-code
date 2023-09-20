# https://leetcode.com/problems/copy-list-with-random-pointer/
from collections import deque
from typing import List, Deque, Optional




# Definition for a Node.
class Node:
    def __init__(self, x: int, next = None, random = None):
        self.val = int(x)
        self.next = next
        self.random = random
    def __str__(self) -> str:
        return str(self.val)


def printLL(node : Optional[Node]):
    def printLLInner(node : Optional[Node]):
        if not node:
            return
        print(node, end=" ")
        printLLInner(node.next)
    printLLInner(node=node)
    print()

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # dummy = Node(x=0, next=head)

        if head is None:
            return None

        node = head
        while node:
            newNode = Node(x=node.val)
            newNode.next = node.next
            node.next = newNode

            node = node.next.next

        node = head
        while node:
            node.next.random = node.random.next if node.random else None
            node = node.next.next

        copyHead = head.next

        orgNode = head
        copyNode = copyHead

        while orgNode or copyNode:
            orgNode.next = orgNode.next.next
            copyNode.next = copyNode.next.next if copyNode.next else None

            orgNode = orgNode.next
            copyNode = copyNode.next

        return copyHead


def main():
    head = Node(x=7)
    head.next = Node(x=13)
    head.next.next = Node(x=11)
    head.next.next.next = Node(x=10)
    head.next.next.next.next = Node(x=1)
    solution = Solution()
    ans = solution.copyRandomList(head=head)
    printLL(ans)
    printLL(head)
    # print(f"ans is {solution}")

if __name__ == '__main__':
    main()
