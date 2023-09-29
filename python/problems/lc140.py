# https://leetcode.com/problems/word-break-ii/description/
from typing import List, Deque
from collections import deque
from pprint import pprint

len = len

def f(start : int, s : str, wordDict : List[str], ds : Deque[str], all_s : Deque[str]):

    end = len(s)

    if start == end or start > end or start >= len(s):
        all_s.append(" ".join(ds))
        return

    for w in wordDict:
        n = len(w)
        if n <= end and w == s[start: start + n]:
            ds.append(s[start: start + n])
            f(start + n, s, wordDict, ds, all_s)
            ds.pop()

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str] | Deque[str]:

        all_s = deque()
        ds = deque()
        f(0, s, wordDict, ds, all_s)
        return all_s






def main():
    # s = "catsanddog"
    # wordDict = ["cat","cats","and","sand","dog"]
    # s = "pineapplepenapple"
    # wordDict = ["apple","pen","applepen","pine","pineapple"]
    s = "catsandog"
    wordDict = ["cats","dog","sand","and","cat"]
    solution = Solution()
    ans = solution.wordBreak(s, wordDict)
    print("ans is ----------------------------------------")
    pprint(ans)

if __name__ == '__main__':
    main()
