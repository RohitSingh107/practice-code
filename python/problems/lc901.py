# https://leetcode.com/problems/online-stock-span/
from collections import deque
from typing import List, Deque, Tuple








class StockSpanner:

    def __init__(self):
        self.stack : Deque[Tuple[int,int]] = deque()

    def next(self, price: int) -> int:
        span = 1

        while len(self.stack) > 0 and self.stack[-1][0] <=price:
            _, s = self.stack.pop()
            span += s
        self.stack.append((price, span))

        return span




obj = StockSpanner()
print(obj.next(100))
print(obj.next(80))
print(obj.next(60))
print(obj.next(70))
print(obj.next(60))
print(obj.next(75))
print(obj.next(85))

