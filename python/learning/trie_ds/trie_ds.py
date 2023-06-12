from collections import deque
from treelib import Tree

len = len


class TrieNode():
    
    def __init__(self, char):

        self.char = char
        self.is_end = False
        self.children = {}

    def isContain(self, char) -> bool:
        if char in self.children:
            return True
        return False

    def setEnd(self):
        self.is_end = True

    def get(self, char):
        return self.children[char]

    def put(self, char):
        new_node = TrieNode(char)
        self.children[char] = new_node


class Trie:

    def __init__(self):
        self.root = TrieNode("")

    def insert(self, word : str):

        node = self.root
        for c in word:
            if node.isContain(c):
                node = node.get(c)
            else:
                # new_node = TrieNode(c)
                # node.children[c] = new_node
                # node = new_node
                node.put(c)
                node : TrieNode = node.get(c)

        node.is_end = True



    def search(self, word : str) -> bool:
        node = self.root
        for c in word:
            if node.isContain(c):
                node : TrieNode = node.get(c)
            else:
                return False

        return node.is_end

    def starts_with(self, prefix : str) -> bool:
        node = self.root
        for c in prefix:
            if node.isContain(c):
                node : TrieNode = node.get(c)
            else:
                return False

        return True

    def show(self):
        node = self.root
        q = deque([node])
        tree = Tree()
        tree.create_node(tag= 'root', identifier= node)
        while q:
            u = q.popleft()
            for v in u.children.values():
                q.append(v)
                tree.create_node(tag = v.char, identifier= v, parent= u)
        tree.show()


def main():
    t = Trie()
    keys = ["the", "a", "there", "answer", "any", "bye", "their"]
    for key in keys:
        t.insert(key)
    t.show()


if __name__ == '__main__':
    main()


