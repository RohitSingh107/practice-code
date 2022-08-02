#include <cstring>
#include <numeric>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[205][20005];

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

bool canPartition(vector<int> &nums) {
  int sum = accumulate(nums.begin(), nums.end(), 0);

  memset(dp, -1, sizeof(dp));

  if (sum & 1) {
    return false;
  }
  return subsetSum(nums.size() - 1, sum / 2, nums);
}

int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
