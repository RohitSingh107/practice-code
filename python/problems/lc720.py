from collections import deque
from typing import List, Deque






len = len

class TrieNode:

    def __init__(self, char : str):
        self.char : str = char
        self.is_end : bool = False
        self.children = {}





class Trie:
    def __init__(self):
        self.root = TrieNode("")

    def insert(self, word : str):
        node = self.root

        for c in word:
            if c in node.children:
                node = node.children[c]
            else:
                new_node = TrieNode(c)
                node.children[c] = new_node
                node = new_node

        node.is_end = True

    def all_prefix(self, word) -> bool:

        node = self.root
        for c in word:
            if c in node.children:
                node = node.children[c]
                if not node.is_end:
                    return False
            else:
                return False

        return True


class Solution:
    def longestWord(self, words: List[str]) -> str:

        trie = Trie()

        for w in words:
            trie.insert(w)

        longestWord = ""
        for w in words:
            if trie.all_prefix(w):
                if len(w) > len(longestWord):
                    longestWord = w
                if len(w) == len(longestWord):
                    longestWord = min(w, longestWord)

        return longestWord


def main():
    # words = ["w","wo","wor","worl","world"]
    words = ["a","banana","app","appl","ap","apply","apple"]
    # words = ["ab", "abc", "a", "bp"]
    # words = ["n", "ni", "nin", "ninj", "ninja", "ninga"]
    # words = ["ab", "ac"]
    solution = Solution()
    print(f"ans is {solution.longestWord(words)}")

if __name__ == '__main__':
    main()
