/* #include <vector> */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") */
/* #pragma GCC optimize("unroll-loops") */
#include <bits/stdc++.h>

using namespace std;

int maximuxValue(int i, int rl, int price[], vector<vector<int>> &dp) {

  if (i == 0) {
    return rl * price[0];
  }

  if (dp[i][rl] != -1) {
    return dp[i][rl];
  }

  // subtracting 1 because rod length starts from 1 not 0;
  if (rl - i - 1 < 0) {
    return dp[i][rl] = maximuxValue(i - 1, rl, price, dp) + 0;
  }

  return dp[i][rl] = max(maximuxValue(i, rl - i - 1, price, dp) + price[i],
                         maximuxValue(i - 1, rl, price, dp) + 0);
}

int cutRod(int price[], int n) {

  /*   // TopDown Recursion */
  /*   vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); */
  /*   return maximuxValue(n - 1, n, price, dp); */

  // BottomUp Tabulation
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int rl = 0; rl <= n; rl++) {
      if (i == 0) {
        dp[0][rl] = rl * price[0];
        continue;
      }
      if (rl - i - 1 < 0) {
        dp[i][rl] = dp[i - 1][rl];
        continue;
      }

      dp[i][rl] = max(dp[i][rl - 1 - i] + price[i], dp[i - 1][rl]);
    }
  }
  return dp[n - 1][n];
}

int32_t main() {
  clock_t _t = clock();

  int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
  /* int price[] = {3, 5, 8, 9, 10, 17, 17, 20}; */

  std::cout << cutRod(price, 8) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
