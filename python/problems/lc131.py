# https://leetcode.com/problems/palindrome-partitioning/description/
from typing import List, Deque
from collections import deque
from pprint import pprint





def isPalindrome(s : str):
    return s == s[::-1]


def pp(start : int, s : str, ds : Deque[str], allS : Deque[Deque[str]]):
    n = len(s)
    # print(f"here1 start is {start}")
    if start == n:
        # print("here2")
        # print(ds)
        allS.append(ds.copy())
        return
 
    for i in range(start, n):
        # print("here3")
        if isPalindrome(s[start: i + 1]):
            # print("here4")
            ds.append(s[start: i + 1])
            pp(i+1, s, ds, allS)
            ds.pop()



class Solution:
    def partition(self, s: str) -> List[List[str]] | Deque[Deque[str]]:

        ds = deque()
        allS = deque()

        pp(0, s, ds, allS)

        return allS




def main():
    s = "aabb"
    solution = Solution()
    ans = solution.partition(s)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
