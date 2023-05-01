from collections import deque
from typing import List, Deque




class Solution:
    def reverseBits(self, n: int) -> int:


        ans = ""
        for _ in range(32):
            if n & 1:
                ans += '1'
            else:
                ans += '0'
            n >>= 1

        # print(ans)
        return int(ans,2)







def main():
    solution = Solution()
    print(f"ans is {solution.reverseBits(43261596)}")

if __name__ == '__main__':
    main()
