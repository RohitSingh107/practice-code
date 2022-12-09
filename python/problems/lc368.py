from typing import List
from itertools import takewhile


def largestDivisibleSubset(nums: List[int]) -> List[int]:

    nums.sort()
    n = len(nums)
    mx = 100000000000000000


    # BottomUp Tabulation
    ans = 1
    dp= [1 for _ in range(n)]
    for i in range(n):
        for j in range(i):
            if nums[i] % nums[j] == 0:

                if dp[j]+1 > dp[i]:
                    print(f"{nums[j]} and {nums[i]}")

                dp[i] = max(dp[i], dp[j] +1)
        ans = max(ans, dp[i])
    print(dp)
    return ans

def main():
    # nums = [3,4,16,8]
    # nums = [1,2,4,8]
    # nums = [1,2,3]
    nums = [1, 3, 16,7,8,4, 25, 9] # 1 3 4 7 8 9 16 25

    print(largestDivisibleSubset(nums))

if __name__ == "__main__":
    main()
