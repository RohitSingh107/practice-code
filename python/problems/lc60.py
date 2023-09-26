# https://leetcode.com/problems/permutation-sequence/description/
from typing import List, Deque
from collections import deque
from pprint import pprint




def kThPermutation(k : int, nums : List[int], factorials : List[int]) -> str:

    # print(f"k is {k}, nums is {nums}")

    if nums == []:
        return ""

    n = len(nums)
    nf = factorials[n]
    slot_size = nf // n

    i = nums[(k // slot_size)]
    # print(f"i is {i}")

    return str(i) + kThPermutation(k % slot_size, [num for num in nums if num != i], factorials)

class Solution:
    def getPermutation(self, n: int, k: int) -> str:

        factorials = [1 for _ in range(n+1)]
        for i in range(2, n +1):
            factorials[i] = factorials[i-1] * i

        return kThPermutation(k-1, [num for num in range(1, n+1)], factorials)







def main():
    solution = Solution()
    ans = solution.getPermutation(4,9)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
