# https://www.geeksforgeeks.org/problems/top-k-numbers3425/1
from collections import deque, defaultdict
from typing import List, Deque, DefaultDict, Tuple
from pprint import pprint




class Solution:
    def kTop(self,a : List[int], N : int, K : int):
        #code here.
        d : DefaultDict[int, int] = defaultdict(int)

        # mx = (-1, -1)

        ans : Deque[List[int]] = deque()

        for i in a:

            d[i] += 1

            if not ans:
                ans.append([i])
                continue

            tmp : Deque[int] = deque()
            inserted = False

            # print("here1")
            # if i == 1:
            #     print("here 1", d, ans)

            for e in ans[-1]:
                if len(tmp) >= K:
                    break
                if d[i] > d[e]:
                    if inserted:
                        tmp.append(e)
                    else:
                        tmp.append(i)
                        inserted = True
                        if len(tmp) >= K:
                            break
                        tmp.append(e)

                elif d[i] < d[e]:
                    tmp.append(e)
                else:
                    if e == i:
                        continue
                    if inserted:
                        tmp.append(e)
                    else:
                        if e > i:
                            tmp.append(i)
                            inserted = True
                            if len(tmp) >= K:
                                break
                            tmp.append(e)
                        else:
                            tmp.append(e)
                if len(tmp) >= K:
                    break
            if not inserted:
                tmp.append(i)
                inserted = True
            ans.append(list(tmp))

        return list(ans)















def main():
    # K=4
    # arr = [5, 2, 1, 3, 2]

    # K=3
    # arr = [2, 1, 2, 1, 2, 1] 

    # K = 3
    # arr = [2, 2, 2, 1, 1, 1]

    K = 5
    arr = [3, 4, 0, 0]

    solution = Solution()
    print(f"ans is {solution.kTop(arr,len(arr),K)}")

if __name__ == '__main__':
    main()
