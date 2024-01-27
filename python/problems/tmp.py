

n, q = input().split()

v = []

for _ in range(int(n)):
    v.append(list(map(int,input().split())))


t = int(input())

vs = []

for _ in range(t):
    s = input()
    vs.append(s)

print(v, vs)
