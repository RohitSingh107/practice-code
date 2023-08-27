# https://leetcode.com/problems/powx-n/

from typing import List

def myPow(x: float, n: int):
    ans = powx(x, abs(n))

    if n < 0:
        return 1 / ans
    else:
        return ans


def powx(x,n):

    ans = 1

    while n:
        # print(f"ans is {ans}, x is {x}, n is {n}")
        if n & 1:
            ans = ans * x
            n = n - 1
        else:
            x = x * x
            n = n // 2

    # print(f"ans is {ans}, x is {x}, n is {n}")
    # ans = ans * x
    return ans


x = 7
n = 11
print(myPow(x,n))
