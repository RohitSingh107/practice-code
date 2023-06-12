

from collections import defaultdict
from pprint import pprint

def trieNode():
    return defaultdict(trieNode)

class WordDictionary:

    def __init__(self):
        self.root = trieNode()
        

    def addWord(self, word: str) -> None:
        
        node = self.root
        for c in word:
            node = node[c]

        node[None]

    def search(self, word: str) -> bool:
        node = self.root

        return self._search(node, word)

        # for i in range(len(word)):
        #     if word[i] == '.':
        #         flag = False
        #         
        #         for ch in node.keys():
        #             flag = flag | self.search(word[i:])
        #
        #         return flag
        #     else:
        #         if word[i] in node:
        #             node = node[word[i]]
        #         else:
        #             return False
        #
        # return None in node

    def _search(self, node, word: str) -> bool:
        # print("word is ", word)
        # pprint(node)

        for i in range(len(word)):
            if word[i] == '.':
                # print("here1")
                flag = False
                
                for ch in node.keys():
                    # print(type(node[ch]))
                    flag = flag | self._search(node[ch], word[i+1:])

                # print("here2")

                return flag
            else:
                if word[i] in node:
                    node = node[word[i]]
                else:
                    return False

        # print(type(node))
        return None in node




# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)

wordDictionary = WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
print(wordDictionary.search("pad")) # return False
print(wordDictionary.search("bad")) # return True
print(wordDictionary.search(".ad")) # return True
print(wordDictionary.search("b..")) # return True
