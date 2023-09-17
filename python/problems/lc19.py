# https://leetcode.com/problems/remove-nth-node-from-end-of-list/
from collections import deque
from typing import List, Deque, Optional




# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next : ListNode = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:


        if head is None:
            return head

        dummy = ListNode(val=0, next=head)

        fp = dummy
        sp = dummy

        for _ in range(n):
            fp = fp.next

        while fp.next is not None:
            fp = fp.next
            sp = sp.next

        sp.next = sp.next.next

        return dummy.next










def main():
    solution = Solution()
    print(f"ans is {solution}")

if __name__ == '__main__':
    main()
