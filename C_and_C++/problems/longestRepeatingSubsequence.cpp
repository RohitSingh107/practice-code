#include <algorithm>
#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int lcsR(int i, int j, string &s1, string &s2) {

  if (i < 0 || j < 0) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ans = INT_MIN;

  ans = max(ans, lcsR(i, j - 1, s1, s2));
  ans = max(ans, lcsR(i - 1, j, s1, s2));
  ans = max(ans, lcsR(i - 1, j - 1, s1, s2) + (s1[i] == s2[j] and i != j));

  return dp[i][j] = ans;
}
int LongestRepeatingSubsequence(string str) {
  memset(dp, -1, sizeof(dp));

  int l = lcsR(str.size() - 1, str.size() - 1, str, str);
  std::cout << "lcs is " << l << std::endl;

  return l;
}

int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
