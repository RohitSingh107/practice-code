#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int editDistanceTopDown(int i, int j, string &s1, string &s2) {
  if (i < 0) {
    // remaining length of s2
    return j + 1;
  }
  if (j < 0) {
    // remaining length of s1
    return i + 1;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ans = INT_MAX;

  // Insertion and deletion
  ans = min(ans, editDistanceTopDown(i, j - 1, s1, s2) + 1);
  // Insertion and deletion
  ans = min(ans, editDistanceTopDown(i - 1, j, s1, s2) + 1);
  // Replace operation
  ans = min(ans, editDistanceTopDown(i - 1, j - 1, s1, s2) + !(s1[i] == s2[j]));

  return dp[i][j] = ans;
}

int editDistanceBottomUp(string &s1, string &s2) {

  int m = s1.size();
  int n = s2.size();

  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == 0) {
        dp[i][0] = i;
        continue;
      }
      if (i == 0) {
        dp[0][j] = j;
        continue;
      }
      dp[i][j] = 0;
    }
  }

  /*   for (int i = 0; i <= m; i++) */
  /*     dp[i][0] = i; */
  /*   for (int j = 0; j <= n; j++) */
  /*     dp[0][j] = j; */

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {

      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = dp[i - 1][j - 1];
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        dp[i][j] = 1 + dp[i][j];
      }
    }
  }

  return dp[m][n];
}

int32_t main() {
  clock_t _t = clock();
  memset(dp, -1, sizeof(dp));

  string s1 = "ABCAB";
  string s2 = "EACB";

  /* string s1 = "a"; */
  /* string s2 = "b"; */
  std::cout << "Top Down: "
            << editDistanceTopDown(s1.size() - 1, s2.size() - 1, s1, s2)
            << std::endl;

  std::cout << "Bottom Up: " << editDistanceBottomUp(s1, s2) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
