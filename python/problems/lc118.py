from collections import deque
from typing import List, Deque





def f(row: List[int]) -> List[int]:
    ans = deque()

    ans.appendleft(row[0])

    for i in range(len(row) -1):
        ans.append(row[i] + row[i+1])

    ans.append(row[len(row) -1])

    return list(ans)
    







class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1,1]]
        numRows -= 2
        ans = deque([[1], [1,1]])
        while numRows:
            ans.append(f(ans[len(ans) -1]))
            numRows -= 1

        return list(ans)






def main():
    numRows = 5
    solution = Solution()
    print(f"ans is {solution.generate(numRows=numRows)}")
    


if __name__ == '__main__':
    main()
