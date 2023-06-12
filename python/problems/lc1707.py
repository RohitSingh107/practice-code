from collections import deque, defaultdict
from typing import List, Deque
from pprint import pprint 







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

        offlineQueries = deque()
        print(len(queries))
        for i in range(len(queries)):
            offlineQueries.append((queries[i][1], (queries[i][0], i)))
        # queries_order = {}
        # print(len(queries))
        # for i in range(len(queries)):
        #     if (queries[i][0], queries[i][1]) in queries_order:
        #         print("already in queries ", (queries[i][0], queries[i][1]))
        #     queries_order[(queries[i][0], queries[i][1])] = i
        # print(len(queries_order))

        # print(queries)
        # print(queries_order)

        nums = sorted(nums)
        offlineQueries = sorted(offlineQueries)

        # pprint( nums)
        # pprint(queries)
        # pprint(queries_order)

        ins = 0
        for q in range(len(offlineQueries)):
            while ins < len(nums) and nums[ins] <= offlineQueries[q][0]:
                print("inserting ", nums[ins])
                insert(node, nums[ins])
                ins += 1

            if ins:
                ans[offlineQueries[q][1][1]] = get_max(node, offlineQueries[q][1][0])
                print("querieng ", queries[q][1])
            # else:
            #     ans[queries_order[queries[q][1]]] = -1
        return ans




def main():
    # nums = [0,1,2,3,4]
    # queries = [[3,1],[1,3],[5,6]]
    # nums = [5,2,4,6,6,3]
    # queries = [[12,4],[8,1],[6,3]]
    # nums = [536870912,0,534710168,330218644,142254206]
    # queries = [[558240772,1000000000],[307628050,1000000000],[3319300,1000000000],[2751604,683297522],[214004,404207941]]
    nums = [760625198,15138539,61033,267654046,133000577,229497,155443,109330,13340119,8260519,981126373,441631490,498767021,171522247,503991705,11276686,176397,23247190,472734721,243117401]
    queries = [[383815038,1000000000],[4194304,1000000000],[633072806,981082380],[875344070,965383924],[31380566,64633365],[4194304,91884],[4194304,158853440],[10839453,224610550],[4194304,349538162],[171815678,403214196],[15355179,1000000000],[938931463,441640682],[23207682,1000000000],[4194304,1000000000],[75686235,1000000000],[86208917,259012],[905942425,1000000000],[692399970,1000000000],[22418605,1000000000],[369403291,1000000000]]
    solution = Solution()
    print(f"ans is {solution.maximizeXor(nums, queries)}")

    # nums = [3,10,5,25,2,8]
    # print(f"ans is {maxXOR(nums)}")

if __name__ == '__main__':
    main()

# t = [1001829712,-1       ,1072246692,1041598465,31424324,4255337,128806273,178019674,263459742,231792511,982548942,1037028800,991482855,976932069,1056452030,86220796,1069985118,927949563,992794696,995270069]
# t = [1001829712,976932069,1072246692,1041598465,31424324,4255337,128806273,178019674,263459742,231792511,982548942,1037028800,991482855,976932069,1056452030,86220796,1069985118,927949563,992794696,995270069]
