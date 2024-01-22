from collections import deque
from typing import List, Deque




#User function Template for python3
class Solution:
    def MaxMoney(self,M : int,B : List[int],A : List[int]):
        # code here

        ans = M

        for i in range(len(A)):
            n = M // B[i]
            r = M % B[i]
            # print("n is ", n, " r is ", r, "cal is ", r + n * A[i])
            ans = max(ans, r + n * A[i])
        return ans












def main():

    # M = 8
    # B = [1,1,2]
    # A = [2,1,1]

    M = 10
    B = [15,5,2]
    A = [6,4,1]

    solution = Solution()
    print(f"ans is {solution.MaxMoney(M,B,A)}")

if __name__ == '__main__':
    main()
