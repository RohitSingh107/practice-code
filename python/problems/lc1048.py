
from typing import List

def f(i : int, j : int, w1: str, w2: str) -> bool:
    if i == -1:
        return True
    if j == -1:
        return False

    if w1[i] == w2[j]:
        return f(i-1, j-1, w1, w2)
    else:
        return f(i, j-1, w1,w2)

def check(w1 : str, w2 : str) -> bool:
    n1 = len(w1)
    n2 = len(w2)
    if n2 - n1 != 1:
        return False

    return f(n1 -1, n2 -1, w1, w2)


    


def longestStrChain(words: List[str]) -> int:

    words.sort(key=len)
    # print(words)

    n = len(words)
    ans = 1



    # BottomUp Tabulation
    dp= [1 for _ in range(n)]
    for i in range(n):
        for j in range(i):
            # print(f"1. i is {i}, j is {j}, words[i] is {words[i]}, words[j] is {words[j]}")
            if check(words[j] , words[i]):
                # print(f"2. i is {i}, j is {j}")
                dp[i] = max(dp[i], dp[j] +1)
        ans = max(ans, dp[i])
    # print(dp)
    return ans


def main():
    # print(check("xb", "xbc"))
    # print(check("xbc", "cxbc"))
    # print(check("cxbc", "pcxbc"))
    # print(check("pcxbc", "pcxbcf"))
    # words = ["a","b","ba","bca","bda","bdca"]
    # words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    words = ["abcd","dbqca"]

    print(longestStrChain(words))


main()
