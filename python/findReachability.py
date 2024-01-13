
import heapq
from collections import defaultdict, deque

def can_reach(graph, start, target):

    if start == target:
        return True
    for n in graph[start]:
        return can_reach(graph, n, target)
    return False

# Example usage:
# graph = {
#     5 : {9: 1},
#     9 : {2: 2, 7: 7},
#     2: {7: 3},
#     7: {}
# }

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


# print(graph)

r = can_reach(graph, s, d)
# r = can_reach(graph, d, s)

print(r)

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
