
from typing import Optional


class Node:
    def __init__(self, val=0, next=None, child=None):
        self.data = val
        self.next = next
        self.child = child


# Don't change the code above.

def printLL(node):
    if node is None:
        return
    print(node.data, end = " ")
    printLL(node.next)

def mergeLL(l1 : Optional[Node], l2 : Optional[Node]) -> Node | None:

    if l1 is None and l2 is None:
        return None
    if l1 is None:
        return l2
    if l2 is None:
        return l1
    
    if l1.data <= l2.data:
        l1.child = mergeLL(l1.child, l2)
        return l1
    else:
        l2.child = mergeLL(l1, l2.child)
        return l2


def flattenLinkedList(head: Node):
    # Write your code here

    if head is None:
        return None
    flatted = flattenLinkedList(head.next)
    head.next = None
    return mergeLL(head, flatted)
