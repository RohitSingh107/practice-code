

import heapq
from collections import defaultdict
from typing import DefaultDict

def fs(g : DefaultDict, initial : int):
    costs = {v: float('infinity') for v in g}
    costs[initial] = 0
    pq = [(0, initial)]

    while pq:
        cd, cv = heapq.heappop(pq)

        if cd > costs[cv]:
            continue

        for nb, w in graph[cv].items():
            d = cd + w

            if d < costs[nb]:
                costs[nb] = d
                heapq.heappush(pq, (d, nb))

    return costs



graph: DefaultDict = defaultdict(dict)

n = int(input())
for _ in range(n):
    ni = int(input())
    graph[ni] = {}

e = int(input())
for _ in range(e):
    fr, fg, cost = list(map(int,input().split()))
    graph[fg].update({fr: cost})

d = int(input())
s = int(input())



result = fs(graph, s)

print(result[d])


