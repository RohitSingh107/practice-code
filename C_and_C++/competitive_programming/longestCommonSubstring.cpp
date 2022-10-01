#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int longestCommonSubstr(string S1, string S2, int n, int m) {

  int dp[n][m];
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      if (i == 0 || j == 0) {

        if (i == 0 && j == 0) {

          if (S1[i] == S2[j]) {
            dp[i][j] = 1;
            ans = max(ans, dp[i][j]);
            continue;
          }
          dp[i][j] = 0;
          continue;
        }

        if (S1[i] == S2[j]) {
          dp[i][j] = 1;
          ans = max(ans, dp[i][j]);
          continue;
        }

        if (i == 0) {
          dp[i][j] = 0;
          continue;
        }

        dp[i][j] = 0;
        continue;
      }

      if (S1[i] == S2[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return ans;
}

int32_t main() {
  clock_t _t = clock();

  string s1 = "FUEMDADGKHUFSUEVJAXRNIVCORHFRQQWNUJQU";
  string s2 = "M";

  std::cout << longestCommonSubstr(s1, s2, s1.size(), s2.size()) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
