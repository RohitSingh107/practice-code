#include <algorithm>
#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int lcs(int i, int j, string s1, string s2) {

  if (i == 0 || j == 0) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  if (s1[i - 1] == s2[j - 1]) {
    return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);
  }

  return dp[i][j] = max(lcs(i, j - 1, s1, s2), lcs(i - 1, j, s1, s2));
}

int minOperations(string str1, string str2) {

  int n = str1.size();
  int m = str2.size();

  /* // TopDown Recursion */
  /* memset(dp, -1, sizeof(dp)); */
  /* int l = lcs(n, m, str1, str2); */
  /* /1* std::cout << "lcs is " << l << std::endl; *1/ */
  /* return n + m - l - l; */

  // BottomUp Tabulation
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        continue;
      }

      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return m + n - 2 * (dp[n][m]);
}

int32_t main() {
  clock_t _t = clock();

  /* std::cout << minOperations("heap", "pea") << std::endl; */
  std::cout << minOperations("geeksforgeeks", "geeks") << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
