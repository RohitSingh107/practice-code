# https://leetcode.com/problems/course-schedule-ii/

from typing import List, Deque
from collections import deque

def findOrder( numCourses: int, prerequisites: List[List[int]]) -> List[int]:

    graph : List[List[int]] = [[] for _ in range(numCourses)]
    indegree = [0 for _ in range(numCourses)]

    for p in prerequisites:
        graph[p[1]].append(p[0])
        indegree[p[0]] += 1


    q : Deque[int] = deque([n for n in range(numCourses) if indegree[n] == 0])
    result = []

    while len(q) != 0:
        v = q.popleft()

        for n in graph[v]:
            indegree[n] -= 1
            if indegree[n] == 0:
                q.append(n)

        result.append(v)

    # print(result)
    if len(result) == numCourses:
        return result
    return []


def main():
    numCourses = 2
    prerequisites = [[1,0]]

if __name__ == "__main__":
    main()
