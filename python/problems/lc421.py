


import collections


# class TrieNode:
#     def __init__(self, ch):
#         self.ch = ch
#         self.children = {}
#
#


def trieNode():
    return collections.defaultdict(trieNode)

class Trie:
    def __init__(self):
        self.root = trieNode()

    def insert(self, i):

        node = self.root

        for b in range(32, -1, -1):
            bit = (i >> b) & 1
            # if bit in node.children:
            #     node = node.children[bit]
            # else:
            #     new_node = TrieNode(bit)
            #     node.children[bit] = new_node
            #     node = new_node
            node = node[bit]

    def get_max(self, i):
        node = self.root

        maxNumber = 0;

        for b in range(32, -1, -1):
            bit = (i >> b) & 1

            if (1 - bit) in node:
                maxNumber = maxNumber | (1 << b)
                node = node[1 - bit]
            else:
                node = node[bit]
        return maxNumber


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
        return best









def maxXOR(nums):
    # Write your code here.   

    trie = Trie()

    for i in nums:
        trie.insert(i)

    ans = 0
    for i in nums:
        ans = max(ans, trie.get_max(i))

    return ans
    



def main():
    nums = [3,10,5,25,2,8]

    sol = Solution()
    print("ans is ", sol.findMaximumXOR(nums))
    print("ans is ", maxXOR(nums))

if __name__ == "__main__":
    main()
