
from collections import deque
from treelib import Tree


class TrieNode:
    def __init__(self, char):
        self.char = char
        self.children = {}
        self.is_end = False

class Trie:

    def __init__(self):
        self.root = TrieNode("")

    def insert(self, word: str) -> None:
        node = self.root

        for c in word:
            if c in node.children:
                node = node.children[c]
            else:
                new_node = TrieNode(c)
                node.children[c] = new_node
                node = new_node

        node.is_end = True

    def search(self, word: str) -> bool:

        node = self.root

        for c in word:
            if c in node.children:
                node = node.children[c]
            else:
                return False

        return node.is_end


    def startsWith(self, prefix: str) -> bool:
        node = self.root

        for c in prefix:
            if c in node.children:
                node = node.children[c]
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

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

def main():
    trie = Trie();
    trie.insert("apple")
    trie.search("apple")
    trie.search("app")
    trie.startsWith("app")
    trie.insert("app")
    trie.search("app")
    trie.show()

if __name__ == "__main__":
    main()
