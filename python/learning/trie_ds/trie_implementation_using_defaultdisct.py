
from collections import defaultdict

def trieNode():
    return defaultdict(trieNode) 

def insert(node, word):
    for c in word:
        node = node[c]
    node[None]

def search(node, word) -> bool:
    for c in word:
        if c in node:
            node = node[c]
        else:
            return False
    return None in node

def starts_with(node, prefix) -> bool:
    for c in prefix:
        if c in node:
            node = node[c]
        else:
            return False
    return True




