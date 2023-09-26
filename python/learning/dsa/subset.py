# https://practice.geeksforgeeks.org/problems/subsets-1613027340/1
from typing import List, Deque
from collections import deque
from itertools import combinations
from pprint import pp, pprint
import copy




def subsetUsingPythonCombinations(nums : List[int]):
    all_ss = deque()
    n = len(nums)
    for r in range(n+1):
        comb = combinations(nums, r)
        all_ss.extend(comb)
    return all_ss

def subsetRecursionWithoutLoop(i : int, ds : Deque[int], all_ss : Deque[Deque], nums : List[int]): # Will not work if there is dublicate elememts
    if i >= len(nums):
        all_ss.append(ds.copy())
        return
 
    # Take
    ds.append(nums[i])
    subsetRecursionWithoutLoop(i+ 1, ds, all_ss, nums)
    ds.pop()

    # Not Tak
    subsetRecursionWithoutLoop(i+1, ds, all_ss, nums)


def subsetRecursionWithLoop(i : int, ds : Deque[int], all_ss : Deque[Deque], nums : List[int]): # Distinct subsets 
    all_ss.append(ds.copy())
 
    for j in range(i, len(nums)):
        if j > i and nums[j] == nums[j-1]: # distinct due to this
            continue
        ds.append(nums[j])
        subsetRecursionWithLoop(j + 1, ds, all_ss, nums)
        ds.pop()

def subsetIterative(nums: List[int]):
    all_ss : Deque[Deque[int]] = deque()
    all_ss.append(deque()) # Empty subset

    for num in nums:
        previous_copy = copy.deepcopy(all_ss)
        # print(f"previous_copy is {previous_copy}, num is {num}")
        for subset in previous_copy:
            subset.append(num)
        all_ss.extend(previous_copy)
    return all_ss

class Solution:
    def subsets(self, A : List[int]): # sorted in lexicographical order except when sorted


        # return sorted(subsetUsingPythonCombinations(A)) # Not distinct
        # # return list(set(sorted(subsetUsingPythonCombinations(A)))) # Distinct

        # return sorted(subsetIterative(A)) # Equivalent as above

        ds = deque()
        all_ss = deque()
 
        # subsetRecursionWithoutLoop(0, ds, all_ss, A) # Not Distinct # Equivalent as above
        # return sorted(all_ss)

        # Above all 3 are Equivalent
 
        A.sort()
        subsetRecursionWithLoop(0, ds, all_ss, A)
        return all_ss









def main():
    # a = [1,2,3]
    # a = [4,4,4,1,4]
    # a =[5, 6, 6, 10, 3, 4, 6, 6, 4]
    # a = [1,7,84,2,8,6,88,799,9,71,54,48,4,45,58]
    # a = [10, 3, 4, 6]
    a = [1,2,5,1]
    solution = Solution()
    ans = solution.subsets(a)
    pprint(ans)
    # print(len(ans))
    # pprint(f"ans is {ans}")

if __name__ == '__main__':
    main() 

"""
My benchmark:

1. RecursiveWithLoop - 221
2. RecursiveWithoutLoop -276
3. PythonUsingCombinations - 353
4. Iterative - 473

"""
