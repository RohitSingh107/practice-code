# https://www.geeksforgeeks.org/problems/heap-sort/1
from collections import deque
from typing import List, Deque
from icecream import ic


class Solution:
    # Heapify function to maintain heap property.
    def heapify(self, arr, n: int, i: int):
        largest = i

        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and arr[left] > arr[largest]:
            largest = left
        if right < n and arr[right] > arr[largest]:
            largest = right

        if i != largest:
            arr[largest], arr[i] = arr[i], arr[largest]
            self.heapify(arr, n, largest)

    # Function to build a Heap from array.
    def buildHeap(self, arr, n):
        for i in range((n - 1) // 2, -1, -1):
            self.heapify(arr, n, i)

    # Function to sort an array using Heap Sort.
    def HeapSort(self, arr, n):
        self.buildHeap(arr,n)

        for i in range(n, 1, -1):
            arr[0], arr[i-1] = arr[i-1], arr[0]
            self.heapify(arr, i-1, 0)




def main():
    # arr = [13, 46, 24, 52, 20, 9]
    # arr = [4,1,3,9,7]
    arr = [10,9,8,7,6,5,4,3,2,1]

    solution = Solution()
    print(f"ans is {solution.HeapSort(arr, len(arr))}")
    print(arr)


if __name__ == '__main__':
    main()
