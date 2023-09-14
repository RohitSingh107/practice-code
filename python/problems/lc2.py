# https://leetcode.com/problems/add-two-numbers/

from collections import deque
from typing import List, Deque, Optional




# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbersWithCarry(l1: Optional[ListNode], l2: Optional[ListNode], carry : int) -> Optional[ListNode]:

    if l1 is None and l2 is None:
        if carry == 0:
            return None
        return ListNode(val=carry)
    if l1 is None and l2 is not None:
        r = l2.val + carry
        mod = r % 10
        carry = r // 10

        node = ListNode(val=mod)
        node.next = addTwoNumbersWithCarry(None, l2.next, carry)
        return node
    if l1 is not None and l2 is None:
        r = l1.val + carry
        mod = r % 10
        carry = r // 10

        node = ListNode(val=mod)
        node.next = addTwoNumbersWithCarry(l1.next, None, carry)
        return node

    # print("here2")
    r = l1.val + l2.val + carry
    mod = r % 10
    carry = r // 10

    node = ListNode(val=mod)
    node.next = addTwoNumbersWithCarry(l1.next, l2.next, carry)
    return node


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        return addTwoNumbersWithCarry(l1, l2, 0) 





def printLL(node):
    if node is None:
        return
    print(node.val, end= ' ')
    printLL(node.next)





def main():
    l1n = [2,4,3]
    l2n = [5,6,4]
    # l1n = [0]
    # l2n = [0]
    # l1n = [9,9,9,9,9,9,9]
    # l2n = [9,9,9,9]

    l1 = ListNode(val=l1n[0])
    l2 = ListNode(val=l2n[0])

    tmp = l1

    for i in l1n[1:]:
        tmp.next = ListNode(val=i)
        tmp = tmp.next

    tmp = l2
    for i in l2n[1:]:
        tmp.next = ListNode(val=i)
        tmp = tmp.next

    # printLL(l1)
    # print()
    # printLL(l2)
    # print()

    solution = Solution()
    ans = solution.addTwoNumbers(l1, l2)
    printLL(ans)
    print()
    # print(f"ans is {solution}")

if __name__ == '__main__':
    main()
