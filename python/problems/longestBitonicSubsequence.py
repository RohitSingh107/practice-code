

from typing import List

def LongestBitonicSequence(nums : List[int]) -> int:

    n = len(nums)

    ans = 1

    dp1 = [1 for _ in range(n)]
    dp2 = [1 for _ in range(n)]

    for i in range(n):
        for j in range(i):
            if nums[j] < nums[i]:
                dp1[i] = max(dp1[i], dp1[j] + 1)


    for i in range(n-1, -1,-1):
        for j in range(n-1, i, -1):
            if nums[j] < nums[i]:
                dp2[i] = max(dp2[i], dp2[j] + 1)

    for i in range(n):
        ans = max(ans, dp1[i] + dp2[i] - 1)

    return ans

def main():
    # nums = [1, 11,2,10,4,5,2,1]
    nums = [1, 2,5,3,2]
    print(LongestBitonicSequence(nums))

if __name__ == "__main__":
    main()
