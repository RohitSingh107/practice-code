inp = int(input())

def threeLetters(n):
    if n == 1: return "one"
    elif n == 2: return "two"
    elif n == 3: return "thr"
    elif n == 4: return "fou"
    elif n == 5: return "fiv"
    elif n == 6: return "six"
    elif n == 7: return "sev"
    elif n == 8: return "eig"
    elif n == 9: return "nin"
    elif n == 0: return "zer"

def doAdd(s):
    i = int(s)
    if i == 0: return 0
    elif i % 9 == 0: return 9
    else: return i % 9

for i in range(inp):
    ans = [x for x in input().split()]
    n = ans[0]
    name = ans[1]
    l1 = 0
    if "." in n:
        l1 = n.index('.')
    l2 = len(n)
    d = l2 - l1
    f = 0
    if n[0] == '-':
        f = 1
        n = n[1:]
    try:
        n = float(n)
        r = True
    except:
        r = False
    if r == False:
        if i < inp - 1:
            print("Invalid")
        else:
            print("Invalid", end = "")
    else:
        sn = format(n, f".{d}e")

        pt = sn.split('e')
        nu = pt[0].split('.')
        k = int(pt[1])
        if f == 1: r = "-"
        else: r = ""
        r += threeLetters(int(nu[0])) + "." + threeLetters(doAdd(nu[1])) + "e"
        if k > 0:
            r += '+'
        elif k < 0:
            r += '-'
        r += threeLetters(abs(int(pt[1]))) + "@"
        if k % 2 != 0:
            for x in range(0, len(name), 2):
                r += name[x]
        else:
            for x in range(1, len(name), 2):
                r += name[x]
    
        if i < inp - 1:
            print(r)
        else:
            print(r, end="")



