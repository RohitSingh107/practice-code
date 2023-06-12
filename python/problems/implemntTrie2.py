from os import *
from sys import *
from collections import *
from math import *



def trieNode():
    return defaultdict(trieNode)

class Trie:
    def __init__(self):

        self.root = trieNode()

    def insert(self, word):
        node = self.root

        for c in word:
            node = node[c]

            if type(node["prefix_count"]) != int:
                node["prefix_count"] = 0

            node["prefix_count"] += 1

        if type(node["end_count"]) != int:
            node["end_count"] = 0
        node["end_count"] += 1

    def countWordsEqualTo(self, word):
        node = self.root
        for c in word:
            if c in node:
                node = node[c]
            else:
                return 0

        if type(node["end_count"]) != int:
            node["end_count"] = 0
        return node["end_count"]

    def countWordsStartingWith(self, word):
        node = self.root
        for c in word:
            if c in node:
                node = node[c]
            else:
                return 0
        if type(node["prefix_count"]) != int:
            node["prefix_count"] = 0
        return node["prefix_count"]

    def erase(self, word):
        # Write your code here.
        node = self.root
        for c in word:
            if c in node:
                node = node[c]
                if type(node["prefix_count"]) != int:
                    node["prefix_count"] = 0
                node["prefix_count"] -= 1
            else:
                return

        if type(node["end_count"]) != int:
            node["end_count"] = 0
        node["end_count"] -= 1
