# https://leetcode.com/problems/palindrome-linked-list/
from collections import deque
from typing import List, Deque, Optional



# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next : ListNode | None = next
    def __str__(self) -> str:
        return str(self.val)


def reverseLL(head : Optional[ListNode]):
    prv = None
    curr = head
    while curr is not None:
        tmp = curr.next
        curr.next = prv
        prv = curr
        curr = tmp

    return prv


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:

        if not head or not head.next:
            return True

        dummy = ListNode(val=0, next=head)
        sp = dummy.next
        fp = dummy.next.next

        mid = head.next

        # print(dummy)
        # print(sp)
        # print(fp)


        while True:

            if fp.next is None:
                mid = sp.next
                break

            if fp.next.next is None:
                mid = sp.next.next
                break

            sp = sp.next
            fp = fp.next.next

        start = head
        mid = reverseLL(mid)
        # print(f"star is {start}, mid is {mid}")
        while True:
            if mid is None:
                return True
            # print(f"star is {start}, mid is {mid}")
            if head.val != mid.val:
                return False

            head = head.next
            mid = mid.next
        return False










def main():

    # head = ListNode(val=1)
    # head.next = ListNode(val=2)
    # head.next.next = ListNode(val=2)
    # head.next.next.next = ListNode(val=1)
    head = ListNode(val=1)
    head.next = ListNode(val=0)
    head.next.next = ListNode(val=1)
    solution = Solution()
    print(f"ans is {solution.isPalindrome(head=head)}")

if __name__ == '__main__':
    main()
