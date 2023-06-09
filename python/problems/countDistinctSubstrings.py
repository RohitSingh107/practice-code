

class TrieNode:
    def __init__(self):
        self.links = [None for _ in range(26)]

    def containKey(self, ch):
        return self.links[ord(ch) - ord('a')] != None

    def get(self, ch):
        return self.links[ord(ch) - ord('a')]

    def put(self, ch, node):
        self.links[ord(ch) - ord('a')] = node

def countDistinctSubstrings(s):

    root = TrieNode()
    count = 0
    n = len(s)
    for i in range(n):
        node = root
        for j in range(i, n):
            if not node.containKey(s[j]):
                node.put(s[j], TrieNode())
                count += 1
            node = node.get(s[j])

    return count + 1

        

def main():
    s = "abc"
    # s = "ababa"
    print(countDistinctSubstrings(s))

if __name__ == "__main__":
    main()
