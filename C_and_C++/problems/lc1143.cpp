#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int lcs(int i, int j, string &s1, string &s2) {

  if (i < 0 || j < 0) {
    return 0;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ans = lcs(i, j - 1, s1, s2);
  ans = max(ans, lcs(i - 1, j, s1, s2));
  ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));

  return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
  memset(dp, -1, sizeof(dp));
  return lcs(text1.size() - 1, text2.size() - 1, text1, text2);
}

int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
