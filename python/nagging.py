
import heapq
from collections import defaultdict, deque


def find_paths(graph, start, end, ans, path=[]):
    path = path + [start]

    if start == end:
        for num in path:
            ans.add(num)
    
    if start not in graph:
        return
    
    for node in graph[start]:
        if node not in path:
            find_paths(graph, node, end, ans, path.copy())

# Example usage:
# graph = {
#     5 : {9: 1},
#     9 : {2: 2, 7: 7},
#     2: {7: 3},
#     7: {}
# }
#
# d = 7
# s = 9


graph = defaultdict(deque)

n = int(input())
for _ in range(n):
    ni = int(input())
    graph[ni] = deque([])

e = int(input())
for _ in range(e):
    follower, following = list(map(int,input().split()))
    # graph[following].update({follower: cost})
    graph[following].append(follower)

d = int(input())
s = int(input())

ans = set()

find_paths(graph, s, d, ans)

# print([a for a in ans if a != s])
for n in ans:
    if n != s:
        print(n, end="")
print()
# print(graph)

# r = can_reach(graph, d, s)


# print(f"Shortest distance from {s} to {d}: {shortest_distance}")
# print(graph)



# 4
# 2
# 5
# 7
# 9
# 4
# 2 9
# 7 2
# 7 9
# 9 5
# 7
# 9
