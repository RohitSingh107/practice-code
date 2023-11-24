from collections import deque
from typing import List, Deque







def possible(dist, k, stalls):
    cows = 1
    last_placed_cow = stalls[0]

    for s in stalls[1:]:
        if s - last_placed_cow >= dist:
            cows += 1
            last_placed_cow = s
            if cows >= k:
                return True

    return False


def aggressiveCows(stalls, k):
    # Write your code here.
    stalls = sorted(stalls)
    lo = 1
    hi = stalls[-1] - stalls[0]

    while lo <= hi:
        mid = (lo + hi) // 2
 
        if possible(mid, k, stalls):
            lo = mid + 1
        else:
            hi = mid - 1

    return hi




def main():
    # stalls = [0, 3, 4, 7, 10, 9]
    # k = 4

    # stalls = [4,2,1,3, 6]
    # k= 2

    stalls = [1,2,3]
    k = 2

    print(f"ans is {aggressiveCows(stalls, k)}")

if __name__ == '__main__':
    main()
