


class TrieNode:
    def __init__(self, ch):
        self.ch = ch
        self.children = {}



class Trie:
    def __init__(self):
        self.root = TrieNode(-1)

    def insert(self, i):

        node = self.root

        for b in range(32, -1, -1):
            bit = (i >> b) & 1
            if bit in node.children:
                node = node.children[bit]
            else:
                new_node = TrieNode(bit)
                node.children[bit] = new_node
                node = new_node
        # node.is_end = True

    def get_max(self, i):
        node = self.root

        maxNumber = 0;

        for b in range(32, -1, -1):
            bit = (i >> b) & 1

            if (1 - bit) in node.children:
                maxNumber = maxNumber | (1 << b)
                node = node.children[1 - bit]
            else:
                node = node.children[bit]

        return maxNumber


def maxXOR(n, m, arr1, arr2):
    # Write your code here.   

    trie = Trie()

    for i in arr1:
        trie.insert(i)

    ans = 0
    for i in arr2:
        ans = max(ans, trie.get_max(i))

    return ans



def main():
    n = 3
    m = 3
    arr1 = [25, 10, 2]
    arr2 = [8, 5, 3]

    print("ans is ", maxXOR(n,m, arr1, arr2))

if __name__ == "__main__":
    main()
