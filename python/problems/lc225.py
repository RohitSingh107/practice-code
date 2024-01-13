# https://leetcode.com/problems/implement-stack-using-queues/description/
from collections import deque
from typing import List, Deque


# class MyStack:
#     def __init__(self):
#         self.q1 = deque() # for output
#         self.q2 = deque() # for input
#
#     def push(self, x: int) -> None:
#
#         self.q2.append(x)
#
#         while len(self.q1) > 0:
#             e = self.q1.popleft()
#             self.q2.append(e)
#
#         self.q1, self.q2 = self.q2, self.q1
#
#     def pop(self) -> int:
#         return self.q1.popleft()
#
#     def top(self) -> int:
#         return self.q1[0]
#
#     def empty(self) -> bool:
#         return len(self.q1) == 0


class MyStack:
    def __init__(self):
        self.queue = deque()

    def push(self, x: int) -> None:
        n = len(self.queue)
        self.queue.append(x)

        for _ in range(n):
            self.queue.append(self.queue.popleft())

    def pop(self) -> int:
        return self.queue.popleft()

    def top(self) -> int:
        return self.queue[0]

    def empty(self) -> bool:
        return len(self.queue) == 0


def main():
    pass


if __name__ == "__main__":
    main()
