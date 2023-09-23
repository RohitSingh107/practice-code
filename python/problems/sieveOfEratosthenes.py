from collections import deque
from typing import List, Deque







import math
class Solution:
    def sieveOfEratosthenes(self, N):
    	#code here 
    	
        pf = [True for _ in range(N+1)]
        pf[0] = pf[1] = False
        for i in range(math.ceil(math.sqrt(N))):
            if pf[i]:
                for j in range(2*i, N+1, i):
                    # print(f"pfj is {pf[j]} i is {i}, j is {j}")
                        # print("here1")
                    pf[j] = False
        return [i for i in range(N+1) if pf[i]]
    	








def main():
    solution = Solution()
    print(f"ans is {solution.sieveOfEratosthenes(35)}")

if __name__ == '__main__':
    main()
