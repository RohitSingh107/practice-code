# https://leetcode.com/problems/permutations/
from typing import List, Deque
from collections import deque
from pprint import pprint


def f(n: int, m : int, v : int, graph: List[List[bool]], colored : List[int]) -> bool:

    ans = False

    for color in range(m):
        colorAvailable = True
        for i in range(v):
            if graph[n][i]:
                if colored[i] == color:
                    colorAvailable = False
                    break

        if colorAvailable:
            if n == v - 1:
                return True

            colored[n] = color
            ans = ans or f(n+1, m, v, graph, colored)
            colored[n] = -1
            if ans:
                return True

    return ans


def graphColoring(graph, k, V):

    colored = [-1] * V
    return f(0, k, V, graph, colored)


def main():
    k = 2
    graph = [[0,1,0], [1,0,1], [0,1,0]]
    ans = graphColoring(graph, k, len(graph))
    print("ans is ----------------------------------------")
    pprint(ans)


if __name__ == "__main__":
    main()
