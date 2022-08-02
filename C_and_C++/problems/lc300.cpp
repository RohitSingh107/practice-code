#include <climits>
#include <cstring>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int N = 2500;
int dp[N];

int lis(int i, vector<int> &nums) {

  if (dp[i] != -1) {
    return dp[i];
  }

  int ans = 1;

  for (int j = 0; j < i; j++) {
    if (nums[j] < nums[i]) {
      ans = max(ans, lis(j, nums) + 1);
    }
  }
  return dp[i] = ans;
}

int lengthOfLIS(vector<int> &nums) {
  memset(dp, -1, sizeof(dp));

  int ans = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    ans = max(ans, lis(i, nums));
  }
  return ans;
}

int32_t main() {
  clock_t _t = clock();

  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  /* vector<int> nums = {0, 1, 0, 3, 2, 3}; */
  /* vector<int> nums = {7, 7, 7, 7, 7, 7, 7}; */

  std::cout << lengthOfLIS(nums) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
