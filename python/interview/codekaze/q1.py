
from typing import List

def f(i : int, j: int, a : List[int], b: List[int], x) -> int:
    ans = 0
    for j in range(len(a)):
        if j == i:
            continue
        else:
            notTake = f(i, j+1, a, b, x)
            take = f(i, j+1, a, b, x) + b[j]

    return ans


def score_and_cost(n: int, a: List[int], b: List[int], x: int) -> int:

    ans = 0
    for i in range(n):
        ans = min(ans, f(i, 0, a, b, x))
    return ans
