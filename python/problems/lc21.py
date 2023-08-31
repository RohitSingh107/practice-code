# https://leetcode.com/problems/merge-two-sorted-lists/
from collections import deque
from typing import List, Deque, Optional







# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next : ListNode= next

class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> Optional[ListNode]:

        if list1 is None and list2 is None:
            return None

        if list1 is None:
            return list2
        if list2 is None:
            return list1

        if list2.val < list1.val:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2
        else:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1









def main():

    l1 = ListNode(-9)
    l1.next = ListNode(3)


    l2 = ListNode(5)
    l2.next = ListNode(7)
    # l1 = ListNode(1)
    # l1.next = ListNode(2)
    # l1.next.next = ListNode(4)
    #
    #
    # l2 = ListNode(1)
    # l2.next = ListNode(3)
    # l2.next.next = ListNode(4)

    solution = Solution()
    ans = solution.mergeTwoLists(l1,l2)
    print(f"ans is {ans.val}")
    print(f"ans is {ans.next.val}")
    print(f"ans is {ans.next.next.val}")
    print(f"ans is {ans.next.next.next.val}")
    # print(f"ans is {ans.next.next.next.next.val}")
    # print(f"ans is {ans.next.next.next.next.next.val}")

if __name__ == '__main__':
    main()
