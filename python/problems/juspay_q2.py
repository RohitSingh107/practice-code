
from collections import defaultdict, deque
from typing import DefaultDict, Set, List


def fr(g : defaultdict, root : int, leaf : int, res : Set[int], route : List[int]=[]):
    route = route + [root]

    if root == leaf:
        for n in route:
            res.add(n)
    if root not in g:
        return
    for node in g[root]:
        if node not in route:
            fr(g, node, leaf, res, route.copy())


g : DefaultDict = defaultdict(deque)

n = int(input())
for _ in range(n):
    ni = int(input())
    g[ni] = deque([])

e = int(input())
for _ in range(e):
    follower, following = list(map(int,input().split()))
    g[following].append(follower)

des = int(input())
src = int(input())

res : Set[int] = set()

fr(g, src, des, res)

for n in res:
    if n != src:
        print(n, end="")
print()

