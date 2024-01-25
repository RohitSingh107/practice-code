# https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1
from collections import deque
from typing import List, Deque, Tuple






class Solution:
    def solve (self,num1 : int,num2 : int) -> int:
        #code here

        N = 10000
        primes = [True] * N
        visited = [False] * N

        primes[0] = False
        primes[1] = False

        for i in range(2,100):
            if primes[i]:
                for j in range(2*i,N, i):
                    primes[j] = False

        # print(list(enumerate(primes)))

        q : Deque[Tuple[int,int]] = deque()

        q.append((0, num1))
        visited[num1] = True

        while len(q):

            d, n = q.popleft()

            for i in range(4):
                for j in range(10):
                    if i == 0 and j == 0:
                        continue


                        # return 0
                    ns = str(n)
                    new = int(ns[:i] + str(j) + ns[i+1:])

                    if new == num2:
                        return d + 1

                    if primes[new] and not visited[new]:
                        q.append((d+1, new))
                        visited[new] = True

        return -1









def main():
    num1 = 1033 
    num2 = 8179

    solution = Solution()
    print(f"ans is {solution.solve(num1, num2)}")

if __name__ == '__main__':
    main()
