from collections import deque
from typing import List, Deque, Optional







# https://leetcode.com/problems/rotate-list/description/
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return str(self.val)

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        if head is None:
            return None
        if head.next is None:
            return head

        dummy = ListNode(next=head)
        fp = dummy
        sp = dummy

        n = 1

        c = 0

        last_node = fp.next
        while True:
            sp = sp.next
            fp = fp.next.next
            c += 1


            if fp is None:
                # print(f"even n is {c}")
                n = 2 * c - 1
                break

            if fp.next is not None:
                last_node = fp.next

            if fp.next is None:
                # print(f"odd n is {c}")
                n = 2 * c
                last_node = fp
                break
        k = n - (k % n)
        if k == 0 or k == n:
            return head
        # print(f"n is {n}, c is {c}, k is {k}, last_node is {last_node}")
        i = 0
        p = dummy
        while True:
            p = p.next
            i += 1
            if i == k:
                new_head = p.next
                p.next = None
                last_node.next = dummy.next
                return new_head






def main():
    head = ListNode(val=1)
    head.next = ListNode(val=2)
    # head.next.next = ListNode(val=3)
    # head.next.next.next = ListNode(val=4)
    # head.next.next.next.next = ListNode(val=5)
    solution = Solution()
    ans = solution.rotateRight(head, k = 2)
    print(ans)

if __name__ == '__main__':
    main()
