from collections import deque
from typing import List, Deque



bop = {
        'F' : False,
        'T' : True
        }

def f(i, j, isTrue, s, dp) -> int:

    if i > j:
        return 0

    if dp[i][j][isTrue] != -1:
        return dp[i][j][isTrue]

    # print(f"i is {i}, j is {j}")
    if i == j:
        if isTrue:
            # print(f"i is {i}, j is {j}")
            return int(s[i] == 'T')
        else:
            return int(s[i] == 'F')


    ans = 0
    # print("here1------------------------------")

    for k in range(i+1, j, 2):

        # print(f"i is {i}, j is {j}, k is {k}")
        lT = f(i, k-1, True, s, dp)
        lF = f(i, k-1, False, s, dp)
        rT = f(k+1, j, True, s, dp)
        rF = f(k+1, j, False, s, dp)

        if s[k] == '|':
            if isTrue:
                ans += lT * rT + lT * rF + lF * rT
            else:
                ans += lF * rF
        elif s[k] == '&':
            if isTrue:
                ans += lT * rT
            else:
                ans += lT * rF + lF * rT + lF * rF
        else:
            if isTrue:
                ans += lT * rF + lF * rT
            else:
                ans += lT * rT + lF * rF

    dp[i][j][isTrue] = ans % 1003


    return dp[i][j][isTrue]




class Solution:
	# @param A : string
	# @return an integer
    def cnttrue(self, A : str) -> int:

        l = len(A)

        # dp = [[[-1 for _ in range(2)] for _ in range(l+1)] for _ in range(l+1)]
        # return f(0, l -1, True, A, dp)
        dp = [[[0 for _ in range(2)] for _ in range(l+1)] for _ in range(l+1)]
        
        for i in range(l-1, 0 -1, -1):
            for j in range(i, l):

                for b in range(2):
                    if i > j:
                        dp[i][j][b] = 0

                    # print(f"i is {i}, j is {j}")
                    if i == j:
                        if b:
                            # print(f"i is {i}, j is {j}")
                            dp[i][j][b] = int(A[i] == 'T')
                        else:
                            dp[i][j][b] = int(A[i] == 'F')

                        continue

                    
                    ans = 0
                    # print("here1------------------------------")

                    for k in range(i+1, j, 2):

                        # print(f"i is {i}, j is {j}, k is {k}")
                        lT = dp[i][k-1][1]
                        lF = dp[i][k-1][0]
                        rT = dp[k+1][j][1]
                        rF = dp[k+1][j][0]

                        if A[k] == '|':
                            if b:
                                ans += lT * rT + lT * rF + lF * rT
                            else:
                                ans += lF * rF
                        elif A[k] == '&':
                            if b:
                                ans += lT * rT
                            else:
                                ans += lT * rF + lF * rT + lF * rF
                        else:
                            if b:
                                ans += lT * rF + lF * rT
                            else:
                                ans += lT * rT + lF * rF

                    dp[i][j][b] = ans % 1003
        # print(dp)
        return dp[0][l-1][1]



def main():
    # A = "T|F"
    # A = "T^T^F"
    # A = "T^F|F"
    A = "T|T&F^T"
    solution = Solution()
    print(f"ans is {solution.cnttrue(A)}")

if __name__ == '__main__':
    main()
