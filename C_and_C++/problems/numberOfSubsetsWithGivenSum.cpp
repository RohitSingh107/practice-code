#include "bits/stdc++.h"
#include <vector>

using namespace std;

int mod = (int)(1e9 + 7);

int f(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {

  /* if (target == 0) { */
  /*   return 1; */
  /* } */

  if (i == 0) {
    if (target == 0 && nums[0] == 0)
      return 2;
    if (target == 0 || target == nums[0])
      return 1;
    return 0;
  }

  if (target < 0) {
    return 0;
  }

  if (dp[i][target] != -1) {
    return dp[i][target] % mod;
  }

  dp[i][target] =
      f(i - 1, target - nums[i], nums, dp) + f(i - 1, target, nums, dp);
  return dp[i][target] % mod;
}

int perfectSum(int arr[], int n, int sum) {

  /* // TopDown Recursion */
  /* vector<int> nums(arr, arr + n); */
  /* vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1)); */
  /* return f(n - 1, sum, nums, dp); */

  // BottomUp Tabulation
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (i == 0) {

        if (j == 0 && arr[0] == 0) {
          dp[i][j] = 2;
          continue;
        }

        if (j == 0 || j == arr[0]) {
          dp[i][j] = 1;
          continue;
        }

        dp[i][j] = 0;
        continue;
      }
      /* dp[i][j] = dp[i-1][j - arr[i]] + dp[i-1][j]; */
      dp[i][j] = dp[i - 1][j] % mod;
      if (j - arr[i] >= 0) {
        dp[i][j] += dp[i - 1][j - arr[i]] % mod;
      }
    }
  }
  return dp[n - 1][sum] % mod;
}

int main() {

  int n = 3;
  int sum = 1;
  int arr[n] = {0, 0, 1};

  std::cout << perfectSum(arr, n, sum) << std::endl;
}
