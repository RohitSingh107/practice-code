# https://leetcode.com/problems/valid-parentheses/description/
from collections import deque
from typing import List, Deque


class Solution:
    def isValid(self, s: str) -> bool:
        mystack: Deque[str] = deque()

        for b in s:
            match b:
                case "(":
                    mystack.appendleft(b)

                case "{":
                    mystack.appendleft(b)

                case "[":
                    mystack.appendleft(b)

                case ")":
                    if len(mystack) > 0 and mystack[0] == "(":
                        mystack.popleft()
                    else:
                        return False

                case "}":
                    if len(mystack) > 0 and mystack[0] == "{":
                        mystack.popleft()
                    else:
                        return False

                case "]":
                    if len(mystack) > 0 and  mystack[0] == "[":
                        mystack.popleft()
                    else:
                        return False


        return not mystack


def main():
    s = "()[]{}"
    solution = Solution()
    print(f"ans is {solution.isValid(s)}")


if __name__ == "__main__":
    main()
