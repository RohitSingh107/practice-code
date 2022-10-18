/* Given an array arr of size N containing non-negative integers, the task is to
 * divide it into two sets S1 and S2 such that the absolute difference between
 * their sums is minimum and find the minimum difference */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

bool subsetSum(int ind, int sum, vector<int> &nums) {

  if (sum == 0) {
    return true;
  }
  if (ind < 0) {
    return false;
  }

  if (sum < 0) {
    return false;
  }

  if (dp[ind][sum] != -1) {
    return dp[ind][sum];
  }

  return dp[ind][sum] = subsetSum(ind - 1, sum, nums) ||
                        subsetSum(ind - 1, sum - nums[ind], nums);
}

int f(vector<int> &nums, int n) {
  int sum = accumulate(nums.begin(), nums.end(), 0);

  /*   // TopDown Recursion */
  /*   memset(dp, -1, sizeof(dp)); */
  /*   int ans = INT_MAX; */
  /*   for (int i = 0; i <= sum / 2; i++) { */
  /*     if (subsetSum(n - 1, i, nums)) { */
  /*       ans = min(ans, abs(i - (sum - i))); */
  /*     } */
  /*   } */
  /*   return ans; */

  // BottomUp Tabulation
  for (int i = 0; i < n; i++) {
    for (int t = 0; t <= sum; t++) {

      if (t == 0) {
        dp[i][t] = true;
        continue;
      }

      if (i == 0) {
        dp[i][t] = nums[i] == t;
        continue;
      }

      dp[i][t] = dp[i - 1][t];
      if (t < nums[i]) {
        continue;
      }
      dp[i][t] = dp[i][t] || dp[i - 1][t - nums[i]];
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i <= sum / 2; i++) {
    if (dp[n - 1][i]) {
      ans = min(ans, abs(i - (sum - i)));
    }
  }
  return ans;
}

int minDifference(int arr[], int n) {
  vector<int> nums(arr, arr + n);

  return f(nums, n);
}

int32_t main() {
  clock_t _t = clock();

  int n = 4;

  int arr[n] = {1, 6, 5, 11};
  std::cout << minDifference(arr, n) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
