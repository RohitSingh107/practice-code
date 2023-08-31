# https://leetcode.com/problems/middle-of-the-linked-list/
from collections import deque
from typing import List, Deque, Optional






# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> Optional[ListNode]:

        if not head:
            return head

        if head.next is None:
            return head

        if head.next.next is None:
            return head.next
        
        slow = head
        fast = head
        while True:
            slow = slow.next
            fast = fast.next.next

            if fast is None or fast.next is None:
                return slow







def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
