# https://leetcode.com/problems/linked-list-cycle-ii/
from collections import deque
from typing import List, Deque, Optional






# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next : ListNode | None = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head is None:
            return head

        dummy = ListNode(0)
        dummy.next = head

        fp = dummy
        sp = dummy

        while True:
            sp = sp.next
            if sp is None:
                return None
            fp = fp.next.next
            if fp is None or fp.next is None:
                return None

            if fp is sp:
                break

        sp = dummy

        while True:
            sp = sp.next
            fp = fp.next

            if sp is fp:
                return sp









def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
