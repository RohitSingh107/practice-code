import collections

class TrieNode:
    def __init__(self, ch):
        self.ch = ch
        self.children = [None, None]



class Trie:
    def __init__(self):
        self.root = TrieNode(-1)

    def insert(self, i):

        node = self.root

        for b in range(32, -1, -1):
            bit = (i >> b) & 1
            if node.children[bit]:
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

            if node.children[1- bit]:
                maxNumber = maxNumber | (1 << b)
                node = node.children[1 - bit]
            else:
                node = node.children[bit]

        return maxNumber


def maxXOR(nums):
    # Write your code here.   

    trie = Trie()

    for i in nums:
        trie.insert(i)

    ans = 0
    for i in nums:
        ans = max(ans, trie.get_max(i))
        # print("ans is ", ans)

    return ans



class Solution(object):
    def findMaximumXOR(self, nums):
        def Trie(): 
            return collections.defaultdict(Trie)
        
        root = Trie()
        best = 0
        
        for num in nums:
            candidate = 0
            cur = this = root
            for i in range(32)[::-1]:
                curBit = num >> i & 1
                this = this[curBit]
                if curBit ^ 1 in cur:
                    candidate += 1 << i
                    cur = cur[curBit ^ 1]
                else:
                    cur = cur[curBit]
            best = max(candidate, best)
            # print("best is ", best)
        return best

def main():
    nums = [3,10,5,25,2,8]
    # nums = [14,70,53,83,49,91,36,80,92,51,66,70]
    sol = Solution()
    print("ans is ", maxXOR(nums))
    print("ans is ", sol.findMaximumXOR(nums))

if __name__ == "__main__":
    main()
