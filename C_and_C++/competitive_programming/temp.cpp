#include <cstring>
#include <memory>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
int dp[100][100][100];
int c = 0;
int longestCommonSubstring(int i, int j, int count, string s1, string s2) {

  /* std::cout << "i is " << i << " j is " << j << " count is " << count */
  /* << std::endl; */
  if (i < 0 || j < 0) {
    return count;
  }

  if (dp[i][j][count] != -1) {
    return dp[i][j][count];
  }

  c++;
  int ans = count;

  if (s1[i] == s2[j]) {
    ans = max(ans, longestCommonSubstring(i - 1, j - 1, count + 1, s1, s2));
  }

  ans = max(ans, longestCommonSubstring(i, j - 1, 0, s1, s2));
  ans = max(ans, longestCommonSubstring(i - 1, j, 0, s1, s2));

  return dp[i][j][count] = ans;
}

int32_t main() {
  clock_t _t = clock();
  memset(dp, -1, sizeof(dp));

  string s1 = "wqabsrmpmo";
  string s2 = "qbsrmpcnp";

  /*   string s1 = "pan"; */
  /*   string s2 = "pean"; */
  std::cout << longestCommonSubstring(s1.size() - 1, s2.size() - 1, 0, s1, s2)
            << std::endl;
  std::cout << "Total recursive calls with dp:  " << c << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
