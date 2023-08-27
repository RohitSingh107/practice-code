# https://leetcode.com/problems/search-a-2d-matrix/

from typing import List

def searchMatrix(matrix: List[List[int]], target: int) -> bool:


    if target < matrix[0][0]:
        return False

    m = len(matrix)
    n = len(matrix[0])

    low = 0
    hi = m -1

    while low <= hi:
  
        mid = (low + hi) // 2
        print(f"outer: low is {low}, mid is {mid}, hi is {hi}")

        if matrix[mid][0] < target:
            if (mid + 1 < m and matrix[mid+1][0] > target) or mid == m -1:

                r = mid

                low = 0
                hi = n-1
                while hi - low > 1:
                    mid = (low + hi) // 2
                    print(f"inner: r is {r}, low is {low}, mid is {mid}, hi is {hi}")
                    if matrix[r][mid] < target:
                        low = mid+1
                    elif matrix[r][mid] > target:
                        hi = mid-1
                    else:
                        return True
                return(matrix[r][low] == target or matrix[r][hi] == target)
            else:
                low = mid+1
        elif matrix[mid][0] > target:
            hi = mid-1
        else:
            return True


    return False

# matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
# target = 13
matrix = [[1,2,3,4], [5,6,7,8], [9,10,11,12]]

# print(searchMatrix(matrix, -1))

for i in range(-18, 18):
    print(f"{i} : {searchMatrix(matrix, i)}")
