from typing import List
from itertools import takewhile


def largestDivisibleSubset(nums: List[int]) -> List[int]:

    nums.sort()
    # print(f"sorted array: {nums}")
    n = len(nums)

    # BottomUp Tabulation
    dp= [1 for _ in range(n)]
    mxi = 0
    for i in range(n):
        for j in range(i):
            if nums[i] % nums[j] == 0:
                dp[i] = max(dp[i], dp[j] +1)
        if dp[i] > dp[mxi]:
            mxi = i
    ans = []

    level = dp[mxi] -1
    dividend = nums[mxi]
    i = mxi - 1
    selected = nums[mxi]
    ans.append(selected)

    while i >= 0 and level >= 1:
        if dp[i] == level:
            if dividend % nums[i] == 0:
                selected = nums[i]
                dividend = selected
                level = level - 1
                ans.append(selected)
        i -= 1

    ans.reverse()
    return ans

def largestDivisibleSubset2(nums: List[int]) -> List[int]:
    subsets = {-1: set()}
    print(subsets.values(), subsets.keys())
    
    for num in sorted(nums):
        subsets[num] = max([subsets[k] for k in subsets if num % k == 0], key=len) | {num}
    
    return list(max(subsets.values(), key=len))

def main():
    # nums = [3,4,16,8]
    # nums = [1,16,8, 7]
    # nums = [4,8, 10, 240]
    # nums = [1,2,4,8]
    # nums = [1,2,3]
    nums = [1, 3, 18,7,8,4, 25, 12] # 1 3 4 7 8 12 18 25

    print(largestDivisibleSubset2(nums))

if __name__ == "__main__":
    main()
