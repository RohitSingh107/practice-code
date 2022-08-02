#include <algorithm>
#include <cstring>
#include <iterator>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

int lcs(int i, int j, string &s1, string &s2) {

  if (i < 0 || j < 0) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ans = INT_MIN;

  ans = max(ans, lcs(i, j - 1, s1, s2));
  ans = max(ans, lcs(i - 1, j, s1, s2));
  ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));

  return dp[i][j] = ans;
}

int longestPalindromeSubseq(string s) {
  memset(dp, -1, sizeof(dp));

  string s1 = s;
  reverse(s.begin(), s.end());

  int l = lcs(s.size() - 1, s.size() - 1, s1, s);

  return l;
}

int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
