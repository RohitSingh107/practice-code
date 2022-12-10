# https://leetcode.com/problems/number-of-longest-increasing-subsequence/

from typing import List

def findNumberOfLIS(nums: List[int]) -> int:

    n = len(nums)

    dp = [1 for _ in range(n)]
    cnt = [1 for _ in range(n)]

    mx = 1;

    for i in range(n):
        for j in range(i):
            if nums[j] < nums[i]:
                # dp[i] = max(dp[i], dp[j] +1)
                # cnt[i] = cnt[j]
                if dp[j] + 1 > dp[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    cnt[i] = cnt[j]
                    continue
                if dp[j] + 1 == dp[i]:
                    cnt[i] += cnt[j]
        mx = max(mx, dp[i])

    ans = 0;
    for i in range(n):
        if dp[i] == mx:
            ans += cnt[i];

    # print(mx)
    # print(dp)
    # print(cnt)
    return ans


def main():
    # nums = [1,3,5,4,7]
    nums = [2,2,2,2,2]
    print(findNumberOfLIS(nums))

if __name__ == "__main__":
    main()
