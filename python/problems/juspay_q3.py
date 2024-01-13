
from collections import defaultdict, deque

from typing import DefaultDict

def check(g : DefaultDict, root : int, t : int) -> bool:

    ans = False

    if root == t:
        return True
    for n in g[root]:
        ans |= check(g, n, t)
        if ans:
            return True
    return ans



g : DefaultDict = defaultdict(deque)

n = int(input())
for _ in range(n):
    ni = int(input())
    g[ni] = deque([])

e = int(input())
for _ in range(e):
    fr, fg = list(map(int,input().split()))
    g[fg].append(fr)

dest = int(input())
src = int(input())



print(check(g, src, dest))



