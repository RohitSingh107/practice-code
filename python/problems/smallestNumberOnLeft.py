
# https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
from collections import deque
from typing import List, Deque








class Solution:
    def leftSmaller(self, n, a):
        # code here

        s = deque()
        ans = deque()
        print(a)

        for i in a:
            while len(s) > 0 and i <= s[0]:
                s.popleft()

            if not s:
                print("i is ", i, "stack is", s)
                ans.append(-1)
            else:
                print("i is ", i, "stack is", s)
                ans.append(s[0])

            s.appendleft(i)
        return list(ans)








def main():
    a = [1, 5, 0, 3, 4, 5]
    solution = Solution()
    print(f"ans is {solution.leftSmaller(len(a), a)}")

if __name__ == '__main__':
    main()
