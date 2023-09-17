# https://leetcode.com/problems/intersection-of-two-linked-lists/
from collections import deque
from typing import List, Deque, Optional



# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def toHash(node : ListNode):
    return hash((node.val, node.next))

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:

        
        d = {}
        while headA is not None:
            d[toHash(headA)] = headA
            headA = headA.next

        while headB is not None:
            h = toHash(headB)
            if h in d and d[h] is headB:
                # print(d[toHash(headB)] is headB)
                return headB
            headB = headB.next
        


        return None









def main():
    # a = ListNode(7)
    # print(hash(7))
    # print(hash(None))
    # print(hash((7, None)))
    # print(toHash(a))
    solution = Solution()
    # print(f"ans is {solution}")

if __name__ == '__main__':
    main()
