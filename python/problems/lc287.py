
from typing import List
# from itertools import accumulate
# from functools import reduce
from collections import defaultdict

import operator as op

def f(n1, n2):
    return n1 ^ n2

def findDuplicate(self, nums: List[int]) -> int:

    # x = reduce(op.xor,range(1,len(nums)),0)
    #
    # return reduce(op.xor, nums, x)

    d = defaultdict(bool)

    for n in nums:
        if d[n]:
            return n
        else:
            d[n] = True



