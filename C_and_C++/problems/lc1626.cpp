#include <algorithm>
#include <climits>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

/* int lis(int i, int p, vector<pair<int, int>> &nums, vector<vector<int>> dp) {
 */

/*   if (i == -1) { */
/*     return 0; */
/*   } */

/*   if (dp[i][p] != -1) { */
/*     return dp[i][p]; */
/*   } */

/*   if (nums[i].second <= p) { */

/*     return dp[i][p] = max(lis(i - 1, nums[i].second, nums, dp) +
 * nums[i].second, */
/*                           lis(i - 1, p, nums, dp)); */
/*   } */
/*   return dp[i][p] = lis(i - 1, p, nums, dp); */
/* } */

int bestTeamScore(vector<int> &scores, vector<int> &ages) {

  vector<pair<int, int>> p;
  int n = ages.size();

  int mx = INT_MIN;

  for (int i = 0; i < n; i++) {
    p.push_back({ages[i], scores[i]});
    mx = max(mx, scores[i]);
  }
  sort(p.begin(), p.end());

  /* mx = 1000000; // Given in question */

  vector<vector<int>> dp(n, vector<int>(mx + 1, 0));

  for (int i = 0; i <= mx; i++) {
    if (p[0].second <= i) {

      dp[0][i] = p[0].second;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= mx; j++) {
      if (p[i].second <= j) {
        dp[i][j] = max(dp[i - 1][p[i].second] + p[i].second, dp[i - 1][j]);
        continue;
      }

      dp[i][j] = dp[i - 1][j];
    }
  }

  /* return lis(n - 1, mx, p, dp); */
  return dp[n - 1][mx];
}

int32_t main() {
  clock_t _t = clock();

  vector<int> scores = {4, 5, 6, 5}, ages = {2, 1, 2, 1};
  /* vector<int> scores = {1, 2, 3, 5}, ages = {8, 9, 10, 1}; */
  /* vector<int> scores = {1, 3, 5, 10, 15}, ages = {1, 2, 3, 4, 5}; */

  std::cout << bestTeamScore(scores, ages) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
