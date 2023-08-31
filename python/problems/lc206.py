# https://leetcode.com/problems/reverse-linked-list/
from collections import deque
from typing import List, Deque, Optional








# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next : ListNode | None = next

class Solution:
    # def reverseList(self, head: ListNode) -> Optional[ListNode]:
    #
    #     if not head:
    #         return None       
    #
    #     bn = None
    #     cn : ListNode = head
    #     while cn.next is not None:
    #         fn = cn.next
    #         cn.next = bn
    #         bn = cn
    #         cn = fn
    #
    #     cn.next = bn
    #     head = cn
    #     return head
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head is None or head.next is None:
            return head

        newHead = self.reverseList(head.next)

        head.next.next = head
        head.next = None

        return newHead


     




def main():

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)


    solution = Solution()
    ans = solution.reverseList(head)
    print(f"ans is {ans.next.val}")

if __name__ == '__main__':
    main()
