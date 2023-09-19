# https://leetcode.com/problems/reverse-nodes-in-k-group/
from collections import deque
from typing import List, Deque, Optional



# Definition for singly-linked list.



class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseLL(head : ListNode, end : ListNode):
    # print(f"start is {head.val}, end is {end.val}")
    prev = None
    curr = head
    while curr is not end:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    curr.next = prev
    return end

def printLL(node : Optional[ListNode]):
    if not node:
        return
    print(node.val, end = " ")
    printLL(node.next)

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        dummy_head = ListNode(val=0, next=head)
        current_start  = dummy_head
        current_end = dummy_head
        i = 0
        while True:
            current_end = current_end.next
            if current_end is None:
                break
            i += 1
            if i == k:
                next_node = current_end.next
                first = current_start.next
                rev = reverseLL(current_start.next, current_end)

                current_start.next = current_end
                first.next = next_node
                current_start = first
                current_end = first
                i = 0
     
        return dummy_head.next










def main():
    head = ListNode(val=1)
    head.next = ListNode(val=2)
    head.next.next = ListNode(val=3)
    head.next.next.next = ListNode(val=4)
    head.next.next.next.next = ListNode(val=5)
    # printLL(head)
    # print()
    k = 2

    # end = head.next.next.next.next
    # print(f"head: {head.val}, end: {end.val}")
    # rev = reverseLL(head, end)
    # printLL(rev)
    # print()


    solution = Solution()
    ans = solution.reverseKGroup(head=head, k=k)
    # print(ans)
    printLL(ans)
    # print(f"ans is {solution}")

if __name__ == '__main__':
    main()
