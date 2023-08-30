# https://www.codingninjas.com/studio/problems/873366?topList=striver-sde-sheet-problems

from functools import reduce
import operator

# 100
# 100

# 110
# 010
# 010

def missingAndRepeating(arr, n):
    
    xr = reduce(operator.xor, arr, 0)
    xr = reduce(operator.xor, range(1, n+1), xr)

    setBit = xr & ~(xr - 1)
    
    zeroClub = 0
    oneClub = 0

    zeroClub = reduce(operator.xor, filter(lambda x : not x & setBit, arr),zeroClub)
    zeroClub = reduce(operator.xor, filter(lambda x : not x & setBit, range(1,n+1)),zeroClub)

    oneClub = reduce(operator.xor, filter(lambda x : x & setBit, arr),oneClub)
    oneClub = reduce(operator.xor, filter(lambda x : x & setBit, range(1, n+1)),oneClub)

    print(zeroClub, oneClub)
    if oneClub in arr:
        return oneClub, zeroClub
    else:
        return zeroClub, oneClub
















# def missingAndRepeating(arr, n):
#
#     sn =  n * (n+1) / 2
#
#     total = reduce(operator.add, arr, 0)
#
#     rMinusM = total - sn
#
#     sn_square = n * (n + 1) * (2 * n + 1) / 6
#     total_square = reduce(operator.add, [i * i for i in arr], 0)
#
#     sq_diff = total_square - sn_square
#
#     rPlusM = sq_diff / rMinusM
#
#     r = (rPlusM + rMinusM) / 2
#     m = rPlusM - r
#
#     return int(r), int(m)


arr = [4,3,6,2,1,1]

print(missingAndRepeating(arr,len(arr)))
