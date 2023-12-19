from collections import deque
from typing import List, Deque
import heapq



len = len

class MedianFinder:

    def __init__(self):
        self.minheap = []
        self.maxheap = []

    def addNum(self, num: int) -> None:

        if len(self.minheap) == 0:
            heapq.heappush(self.minheap, num)
            print(f"1 minheap {self.minheap}, maxheap: {self.maxheap}")
            return

        if len(self.minheap) == 1 and len(self.maxheap) == 0:
            heapq.heappush(self.minheap, num)
            x = heapq.heappop(self.minheap)
            heapq.heappush(self.maxheap, -x)
            print(f"2. minheap {self.minheap}, maxheap: {self.maxheap}")
            return

        if num > -self.maxheap[0]:
            heapq.heappush(self.minheap, num)
            if len(self.minheap) - len(self.maxheap) > 1:
                x = heapq.heappop(self.minheap)
                heapq.heappush(self.maxheap, -x)
            print(f"3. minheap {self.minheap}, maxheap: {self.maxheap}")
        else:
            heapq.heappush(self.maxheap, -num)
            if len(self.maxheap) - len(self.minheap) > 1:
                x = heapq.heappop(self.maxheap)
                heapq.heappush(self.minheap, -x)
            print(f"4. minheap {self.minheap}, maxheap: {self.maxheap}")


    def findMedian(self) -> float:
        if len(self.minheap) > len(self.maxheap):
            return self.minheap[0]
        elif len(self.minheap) < len(self.maxheap):
            return -self.maxheap[0]
        else:
            return (-self.maxheap[0] + self.minheap[0]) / 2









def main():
    pass

if __name__ == '__main__':
    main()
