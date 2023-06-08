
from os import *
from sys import *
from collections import *
from math import *


class TrieNode:
    def __init__(self, char):
        self.char = char
        self.end_count = 0
        self.prefix_count = 0
        self.children = {}

class Trie:
    def __init__(self):

        self.root = TrieNode("")

    def insert(self, word):
        node = self.root

        for c in word:
            if c in node.children:
                node = node.children[c]
            else:
                new_node = TrieNode(c)
                node.children[c] = new_node
                node = new_node
            node.prefix_count += 1
        node.end_count += 1

    def countWordsEqualTo(self, word):
        node = self.root
        for c in word:
            if c in node.children:
                node = node.children[c]
            else:
                return 0

        return node.end_count

    def countWordsStartingWith(self, word):
        node = self.root
        for c in word:
            if c in node.children:
                node = node.children[c]
            else:
                return 0

        return node.prefix_count

    def erase(self, word):
        # Write your code here.
        node = self.root
        for c in word:
            if c in node.children:
                node = node.children[c]
                node.prefix_count -= 1
            else:
                return
        node.end_count -= 1
