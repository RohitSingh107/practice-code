
import heapq
from collections import defaultdict

def dijkstra(graph, start):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage:
# graph = {
#     5 : {9: 1},
#     9 : {2: 2, 7: 7},
#     2: {7: 3},
#     7: {}
# }

graph = defaultdict(dict)

n = int(input())
for _ in range(n):
    ni = int(input())
    graph[ni] = {}

e = int(input())
for _ in range(e):
    follower, following, cost = list(map(int,input().split()))
    graph[following].update({follower: cost})

d = int(input())
s = int(input())


# print(graph)

result = dijkstra(graph, s)

shortest_distance = result[d]
print(shortest_distance)

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
