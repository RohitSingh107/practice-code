# https://leetcode.com/problems/min-stack/
from pprint import pprint
from typing import List, Deque
from collections import deque


class MinStack:
    def __init__(self):
        self.stack: Deque[int] = deque()
        self.mini: int = -1

    def push(self, val: int) -> None:
        if len(self.stack) == 0:
            self.mini = val
            self.stack.append(val)
            return

        if val < self.mini:
            self.stack.append(2 * val - self.mini)
            self.mini = val
            return

        self.stack.append(val)

    def pop(self) -> None:
        x = self.stack.pop()
        if x < self.mini:
            self.mini = 2 * self.mini - x

    def top(self) -> int:
        if self.stack[-1] < self.mini:
            return self.mini

        return self.stack[-1]

    def getMin(self) -> int:
        return self.mini


def main():
    print("ans is ----------------------------------------")


if __name__ == "__main__":
    main()
