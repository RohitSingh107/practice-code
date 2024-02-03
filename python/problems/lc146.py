from pprint import pprint
from typing import List, Deque, Self, Dict
from collections import deque


class LRUCache:
    class Node:
        def __init__(self, key: int, val: int) -> None:
            self.key: int = key
            self.val: int = val
            self.nxt: Self | None = None
            self.prv: Self | None = None

    def __init__(self, capacity: int):
        self.cap : int = capacity
        self.head = self.Node(-1, -1)
        self.tail = self.Node(-1, -1)
        self.keynodes = {}

        self.head.nxt = self.tail
        self.tail.prv = self.head

    def __addNode(self, node):
        node.nxt = self.head.nxt
        node.prv = self.head
        self.head.nxt.prv = node
        self.head.nxt = node

    def __delNode(self, node):
        node.nxt.prv = node.prv
        node.prv.nxt = node.nxt
        del node

    def get(self, key: int) -> int:
        # print("keynodes: ", self.keynodes)

        if key in self.keynodes:
            node = self.keynodes[key]

            self.__delNode(node)
            self.__addNode(node)

            return node.val

        return -1

    def put(self, key: int, value: int) -> None:

        if key in self.keynodes:
            oldNode = self.keynodes[key]
            del self.keynodes[oldNode.key]
            self.__delNode(oldNode)

        if len(self.keynodes) >= self.cap:
            lastNode = self.tail.prv
            del self.keynodes[lastNode.key]
            self.__delNode(lastNode)

        node = self.Node(key, value)
        self.keynodes[key] = node
        self.__addNode(node)
        # print("after putting ", key, ", keynodes: ", self.keynodes)


# Your LRUCache object will be instantiated and called as such:
obj = LRUCache(2)
print(obj.get(2))
obj.put(2,6)
print(obj.get(1))
obj.put(1,5)
obj.put(1,2)
print(obj.get(1))
print(obj.get(2))



