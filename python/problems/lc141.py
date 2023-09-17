# https://leetcode.com/problems/linked-list-cycle/
from collections import deque
from typing import List, Deque, Optional








# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next : ListNode | None = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:

        if head == None:
            return False

        dummy = ListNode(0)
        dummy.next = head

        sp = dummy.next
        if sp == None:
            return False
        fp = dummy.next.next

        while True:
            if fp is None or fp.next is None:
                return False
            sp = sp.next
            fp = fp.next.next
            if sp is fp:
                return True




        return False





def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
