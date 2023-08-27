
from typing import List
from collections import deque

def merge(intervals: List[List[int]]) -> List[List[int]]:
    ans = deque()
    intervals = sorted(intervals)

    start = intervals[0][0]
    end = intervals[0][1]

    for i in intervals:
        s = i[0]
        e = i[1]
        if s <= end:
            if e > end:
                end = e
        else:
            ans.append([start, end])
            start = s
            end = e
        # print(f"start is {start}, end is {end}")
    ans.append([start, end])


    return list(ans)

intervals = [[1,3],[2,6],[8,10],[15,18]]

print(merge(intervals))
