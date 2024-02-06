# https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
from collections import deque
from typing import List, Deque


class Solution:
    def maxOfMin(self, arr: List[int], n: int) -> List[int]:
        # code here

        ans = [0] * n

        stack: Deque[int] = deque()

        for r in range(n + 1):
            while len(stack) > 0 and (r == n or arr[stack[-1]] > arr[r]):
                mini = arr[stack.pop()]

                l = -1 if len(stack) == 0 else stack[-1]

                window_size = r - l - 1

                ans[window_size - 1] = max(ans[window_size - 1], mini)
            stack.append(r)

        for i in range(n - 2, 0, -1):
            ans[i] = max(ans[i], ans[i + 1])

        return ans


def main():
    # arr =[10,20,30,50,10,70,30]
    # arr = [10, 20, 30]
    arr = [35, 22, 74, 33, 88]

    solution = Solution()
    print(f"ans is {solution.maxOfMin(arr, len(arr))}")


if __name__ == "__main__":
    main()
