# https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258
from collections import deque, defaultdict
from typing import List, Deque





def subarraysWithSumK(a: List[int], b: int) -> int:

    ans = 0

    d = defaultdict(int)

    prefix_xor = 0

    d[0] = 1

    for i in range(len(a)):
        prefix_xor ^= a[i]

        front_rq = prefix_xor ^ b

        # print(f"i is {i}, prefix_xor is {prefix_xor}, front_rq is {front_rq}")

        if front_rq in d:
            ans += d[front_rq]


        d[prefix_xor] += 1
    return ans








def main():
    b = 2
    a = [1,2,3,2]
    # b = 6
    # a = [4,2,2,6,4]
    print(f"ans is {subarraysWithSumK(a,b)}")

if __name__ == '__main__':
    main()
