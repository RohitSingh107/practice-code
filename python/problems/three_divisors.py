from pprint import pp, pprint
from typing import List, Deque
from collections import deque
import math


class Solution:
    def threeDivisors(self, query, q):

        ml = 0
        for i in query:
            ml = max(ml, int(math.sqrt(i)) + 1)

        primes = [True] * (ml + 1)

        primes[0] = primes[1] = False

        for i in range(2, ml):
            if primes[i]:
                for j in range(i * i, ml + 1, i):
                    primes[j] = False

        d = deque()
        for t in query:
            ans = 0
            for i in range(4, t +1):
                if int(math.sqrt(i))**2 == i and primes[int(math.sqrt(i))]:
                    ans += 1

            # print(ans)
            d.append(ans)

        return list(d)

        # pprint(list(enumerate(primes)))


def main():
    query = [6,10]
    solution = Solution()
    ans = solution.threeDivisors(query, len(query))
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
