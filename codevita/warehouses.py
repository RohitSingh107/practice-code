
def rohit(a, b):
    ans = 0
    arrangedw = sorted(filter(lambda k:k!=0,a),reverse=True)
    lo,hi = 0,len(arrangedw) - 1
    
    while lo <= hi:
        if arrangedw[lo]+arrangedw[hi]<=b:
            hi-=1
        lo+=1
        ans+=1
    return ans
inp = list(map(int, input().split()))
x = int(input())
r = rohit(inp, x)
print(r,end="")
