from collections import deque
from typing import List, Deque


def allot(mid, B, books):
    students = 1
    pages_alloted = 0

    for pages in books:

        if pages_alloted + pages <= mid:
            pages_alloted += pages
        else:
            students += 1
            pages_alloted = pages

            if students > B:
                return students

    return students


class Solution:
    def books(self, A, B):

        if len(A) < B:
            return -1

        lo = max(A)
        hi = sum(A)

        while lo <= hi:
            mid = (lo + hi) // 2

            if allot(mid, B, A) <= B:
                hi = mid - 1
            else:
                lo = mid + 1

        return lo


def main():
    # A = [12, 34, 67, 90]
    # B = 2

    # A = [5, 17, 100, 11]
    # B = 4

    # A = [12,12,12,12]
    # B= 4

    # A = [ 73, 58, 30, 72, 44, 78, 23, 9 ] # 110
    # B = 5

    # A = [ 97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24 ]
    # B = 26

    # A = [ 31, 14, 19, 75 ]
    # B = 12
    
    A = [1,2,2,3,1]
    B= 3

    solution = Solution()
    print(f"ans is {solution.books(A, B)}")


if __name__ == "__main__":
    main()
