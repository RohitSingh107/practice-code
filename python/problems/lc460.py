from pprint import pprint
from typing import List, Deque, Self, Dict
from collections import deque, defaultdict

# import sys

class LFUCache:
    class Node:
        def __init__(self, key: int, val: int, freq : int) -> None:
            self.key: int = key
            self.val: int = val
            self.freq = freq
            self.nxt: Self | None = None
            self.prv: Self | None = None

    def __init__(self, capacity: int):
        self.cap : int = capacity
        self.head = self.Node(-1, -1, -1)
        self.tail = self.Node(-1, -1, -1)
        self.keynodes = {}
        self.leastfreq = 0 
        self.freqtable = defaultdict(self.headTailPair)

        self.head.nxt = self.tail
        self.tail.prv = self.head

    def headTailPair(self):
        head = self.Node(-1, -1, -1)
        tail = self.Node(-1, -1, -1)

        head.nxt = tail
        tail.prv = head

        return (head, tail)

    def __addNode(self, node):

        head, _ = self.freqtable[node.freq]

        node.nxt = head.nxt
        node.prv = head
        head.nxt.prv = node
        head.nxt = node

    def __delNode(self, node):
        node.nxt.prv = node.prv
        node.prv.nxt = node.nxt
        del node

    def get(self, key: int) -> int:
        # print("keynodes: ", self.keynodes)

        if key in self.keynodes:
            node = self.keynodes[key]

            self.__delNode(node)
            node.freq += 1
            self.__addNode(node)

            return node.val

        return -1

    def put(self, key: int, value: int) -> None:

        for i in range(1, 2 * 10**5):
            h, t = self.freqtable[i]
            if h.nxt != t or self.leastfreq == 0:
                self.leastfreq = i
                break


        fv = 1

        if key in self.keynodes:
            oldNode = self.keynodes[key]
            fv += oldNode.freq
            del self.keynodes[oldNode.key]
            self.__delNode(oldNode)

        if len(self.keynodes) >= self.cap:
            _, tail = self.freqtable[self.leastfreq]
            lastNode = tail.prv
            del self.keynodes[lastNode.key]
            self.__delNode(lastNode)

        node = self.Node(key, value, fv)
        self.keynodes[key] = node
        self.__addNode(node)
        # print("after putting ", key, ", keynodes: ", self.keynodes)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(2)
# print(obj.get(2))
# obj.put(2,6)
# print(obj.get(1))
# obj.put(1,5)
# obj.put(1,2)
# print(obj.get(1))
# print(obj.get(2))


lfu = LFUCache(2);
print("here1")
lfu.put(1, 1)
print("here2")
lfu.put(2, 2)
print("here3")
print(lfu.get(1))
print("here4")
lfu.put(3, 3)
print("here5")
print(lfu.get(2))
print("here6")
print(lfu.get(3))
print("here7")
lfu.put(4, 4)
print("here8")
print(lfu.get(1))
print("here9")
print(lfu.get(3))
print("here10")
print(lfu.get(4))
print("here11")
