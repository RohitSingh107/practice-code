# https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?leftPanelTab=0
from collections import deque
from typing import List, Deque


def longestSubarrayWithSumK(a: List[int], k: int) -> int:

    n = len(a)
    ans = 0

    i = 0
    j = 0

    current_sum = a[0]

    while i <= j and j < n:
        if current_sum < k:
            j += 1
            if j == n:
                break
            current_sum += a[j]
        elif current_sum > k:
            current_sum -= a[i]
            i += 1
        else:
            l = j - i + 1
            # print(f"i is {i}, j is {j}, l is {l}")
            ans = max(ans, l)

            j += 1
            if j == n:
                break
            current_sum += a[j]

    return ans













def main():
    # k = 3
    # a = [1,2,3,1,1,1,1]
    # k = 2
    # a = [2,2,4,1,2]
    k = 17
    a = [8 ,15 ,17, 0, 11]

    print(f"ans is {longestSubarrayWithSumK(a, k)}")

if __name__ == '__main__':
    main()
