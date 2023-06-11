from collections import deque, defaultdict
from typing import List, Deque







def trieNode():
    return defaultdict(trieNode)


def insert(node, i):

    for b in range(31, -1, -1):
        bit = (i >> b) & 1
        node = node[bit]

def get_max(node, i):

    ans = 0
    for b in range(31, -1, -1):
        bit = (i >> b) & 1
        if (1 - bit) in node:
            node = node[1 - bit]
            ans = ans | (1 << b)
        else:
            node = node[bit]

    return ans







# def maxXOR(nums, root):
#
#     for i in nums:
#         insert(root, i)
#
#     ans = 0
#     for i in nums:
#         ans = max(ans, get_max(root, i))
#
#     return ans

class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:

        ans = [-1 for _ in range(len(queries))] 

        node = trieNode()

        queries_order = {}
        for i in range(len(queries)):
            queries_order[queries[i][1]] = i

        # print(queries)
        # print(queries_order)

        nums = sorted(nums)
        queries = sorted(queries, key= lambda x : x[1])

        # limit = queries[0][1]
        ins = 0
        for q in range(len(queries)):
            while ins < len(nums) and nums[ins] <= queries[q][1]:
                print("inserting ", ins)
                insert(node, nums[ins])
                ins += 1

            if ins:
                ans[queries_order[queries[q][1]]] = get_max(node, queries[q][0])
            # else:
            #     ans[queries_order[queries[q][1]]] = -1
        return ans




def main():
    # nums = [0,1,2,3,4]
    # queries = [[3,1],[1,3],[5,6]]
    # nums = [5,2,4,6,6,3]
    # queries = [[12,4],[8,1],[6,3]]
    nums = [536870912,0,534710168,330218644,142254206]
    queries = [[558240772,1000000000],[307628050,1000000000],[3319300,1000000000],[2751604,683297522],[214004,404207941]]
    solution = Solution()
    print(f"ans is {solution.maximizeXor(nums, queries)}")

    # nums = [3,10,5,25,2,8]
    # print(f"ans is {maxXOR(nums)}")

if __name__ == '__main__':
    main()
