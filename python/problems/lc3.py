# https://leetcode.com/problems/longest-substring-without-repeating-characters/
from collections import deque
from typing import List, Deque








class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        if not s:
            return 0

        ans = 1
        d = {}

        l = 0
        r = 1

        d[s[l]] = l

        while l <= r and r < len(s):
            if s[r] in d and d[s[r]] < r and d[s[r]] >= l:
                l = d[s[r]] + 1
                d[s[r]] = r
            else:
                print("h")
                sl = r - l + 1
                # print(f"l is {l}, r is {r}, sl is {sl}, ans is {ans}, d is {d}")
                ans = max(ans, sl)
                d[s[r]] = r
                r += 1

            # print(f"l is {l}, r is {r}, ans is {ans}, d is {d}")

        return ans





def main():
    s = "abcabcbb"
    # s = "bbbbb"
    # s = "pwwkew"
    # s = "abba"
    solution = Solution()
    print(f"ans is {solution.lengthOfLongestSubstring(s)}")

if __name__ == '__main__':
    main()
