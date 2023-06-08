import abc
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


