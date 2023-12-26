
from collections import deque

n, q = list(map(int, input().split()))

db = deque()

for _ in range(n):
    s, w = input().split()
    db.append((int(w), s))

for _ in range(q):
    s = input()

    try:
        print(max(filter(lambda x : x[1].startswith(s), db))[0])
    except ValueError:
        print(-1)

