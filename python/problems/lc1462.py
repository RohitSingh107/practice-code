# https://leetcode.com/problems/course-schedule/

from typing import List, Deque
from collections import deque

def check(x : int,y :int, courses : List[int]) -> bool:

    xFlag = False
    yFlag = False

    for i in courses:
        if i == y and not xFlag:
            yFlag = True
        if i == x:
            xFlag = True


    return xFlag and yFlag


def checkIfPrerequisite(numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
    

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

    print(result)
    # ans = list(map(lambda x,y : check(x,y), queries))
    ans = list(map(lambda l : check(l[0], l[1], result) , queries))
    return ans


def main():
    # numCourses = 3
    # prerequisites = [[1,2],[1,0],[2,0]]
    # queries = [[1,0],[1,2]]

    # numCourses = 2
    # prerequisites = [[1,0]]
    # queries = [[0,1],[1,0]]
    numCourses = 2 
    prerequisites = []
    queries = [[1,0],[0,1]]
    print(checkIfPrerequisite(numCourses, prerequisites, queries))

if __name__ == "__main__":
    main()
