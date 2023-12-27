# https://leetcode.com/problems/implement-queue-using-stacks/description/
from collections import deque
from typing import List, Deque


class MyQueue:
    def __init__(self):
        self.input_stack = deque()
        self.output_stack = deque()

    def push(self, x: int) -> None:
        self.input_stack.appendleft(x)

    def pop(self) -> int:

        if len(self.output_stack) == 0:
            while len(self.input_stack) > 0:
                self.output_stack.appendleft(self.input_stack.popleft())
        return self.output_stack.popleft()

    def peek(self) -> int:
 
        if len(self.output_stack) == 0:
            while len(self.input_stack) > 0:
                self.output_stack.appendleft(self.input_stack.popleft())
        return self.output_stack[0]

    def empty(self) -> bool:
        return len(self.output_stack) == 0 and len(self.input_stack) == 0


def main():
    pass


if __name__ == "__main__":
    main()
