
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

class Trie :

    def __init__(self) :

        # constructor for the Trie
        self.root = trieNode()
    
    def insert(self, string) :

        # Insert function goes here
        insert(self.root, string)

    
    def search(self, word) :
        
        # Search function goes here
        return search(self.root, word)

        
    def startWith(self, prefix) :
        
        # StartWith function goes here
        return starts_with(self.root, prefix)



def main():
    trie = Trie();
    trie.insert("apple")
    print(trie.search("apple"))
    print(trie.search("app"))
    print(trie.startWith("app"))
    trie.insert("app")
    print(trie.search("app"))

if __name__ == "__main__":
    main()
