#
#
# class TrieNode:
#     def __init__(self):
#         self.links = [None for _ in range(26)]
#
#     def containKey(self, ch):
#         return self.links[ord(ch) - ord('a')] != None
#
#     def get(self, ch):
#         return self.links[ord(ch) - ord('a')]
#
#     def put(self, ch, node):
#         self.links[ord(ch) - ord('a')] = node
#
# def countDistinctSubstrings(s):
#
#     root = TrieNode()
#     count = 0
#     n = len(s)
#     for i in range(n):
#         node = root
#         for j in range(i, n):
#             if not node.containKey(s[j]):
#                 node.put(s[j], TrieNode())
#                 count += 1
#             node = node.get(s[j])
#
#     return count + 1
#
#         
#

def countDistinctSubstring(s):
    se=set()
    se.add("")
    se.add(str(s[0]))
    for i in range(1,len(s)):
        se.add(str(s[i]))
        for j in range(i):
            se.add(str(s[j:i+1]))
            # print(f"i is {i}, j is {j}")
            # print("  added: ", s[j:i+1])
            se.add(str(s[j]))
    
    return len(se)
def main():
    # s = "abc"
    s = "ababa"
    print(countDistinctSubstring(s))

if __name__ == "__main__":
    main()
