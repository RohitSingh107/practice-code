#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[505][505];

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

int minDistance(string word1, string word2) {
  memset(dp, -1, sizeof(dp));

  return editDistanceTopDown(word1.size() - 1, word2.size() - 1, word1, word2);
}

int32_t main() {
  clock_t _t = clock();
  /* memset(dp, -1, sizeof(dp)); */

  /* string s1 = "ABCAB"; */
  /* string s2 = "EACB"; */

  /* std::cout << editDistanceTopDown(s1.size() - 1, s2.size() - 1, s1, s2) */
  /*           << std::endl; */

  /* std::cout << editDistanceBottomUp(s1, s2) << std::endl; */

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
