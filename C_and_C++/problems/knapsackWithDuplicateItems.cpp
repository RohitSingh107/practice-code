#include <algorithm>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int f(int i, int wl, int val[], int wt[], vector<vector<int>> &dp) {

  if (i == 0) {
    return (wl / wt[0]) * val[0];
  }

  if (wl == 0) {
    return 0;
  }

  if (dp[i][wl] != -1) {
    return dp[i][wl];
  }

  if (wl - wt[i] < 0) {
    return dp[i][wl] = f(i - 1, wl, val, wt, dp);
  }

  return dp[i][wl] = max(f(i, wl - wt[i], val, wt, dp) + val[i],
                         f(i - 1, wl, val, wt, dp));
}

int knapSack(int N, int W, int val[], int wt[]) {

  /* // TopDown Recursion */
  /* vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1)); */
  /* return f(N - 1, W, val, wt, dp); */

  // BottomUp Tabulation
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  for (int i = 0; i < N; i++) {
    for (int wl = 0; wl <= W; wl++) {
      if (i == 0) {
        dp[0][wl] = (wl / wt[0]) * val[0];
        continue;
      }
      if (wl == 0) {
        dp[i][0] = 0;
        continue;
      }
      if (wl - wt[i] < 0) {
        dp[i][wl] = dp[i - 1][wl];
        continue;
      }

      dp[i][wl] = max(dp[i][wl - wt[i]] + val[i], dp[i - 1][wl]);
    }
  }
  return dp[N - 1][W];
}
int32_t main() {
  clock_t _t = clock();

  int N = 4, W = 8;
  int val[] = {1, 4, 5, 7};
  int wt[] = {1, 3, 4, 5};

  std::cout << knapSack(N, W, val, wt) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
