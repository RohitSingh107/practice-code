from pprint import pprint
from typing import List, Deque
from collections import deque


# https://leetcode.com/problems/min-stack/
class MinStack:
    def __init__(self):
        self.stack = deque()

    def push(self, val: int) -> None:

        if not self.stack:
            self.stack.appendleft(val)
            return
        
    


    def pop(self) -> None:
        pass

    def top(self) -> int:
        pass

    def getMin(self) -> int:
        pass


def main():
    print("ans is ----------------------------------------")


if __name__ == "__main__":
    main()
