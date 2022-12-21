#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

vector<int> lps(string t2, vector<int> q) {

  int m = t2.size();

  int n = t2.size();
  string t1 = t2;

  reverse(t2.begin(), t2.end());

  std::cout << t1 << " " << t2 << std::endl;

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  int ans = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (t1[i - 1] == t2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      }
    }
  }
  vector<int> store(m + 1, 0);

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] % 2 == 1) {
        store[(dp[i][j] + 1) / 2] = dp[i][j];
      }
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for (int i = 0; i <= m; i++) {
    std::cout << store[i] << " ";
  }
  std::cout << std::endl;

  vector<int> av;
  for (int i : q) {
    /* std::cout << "store is " << store[i] << " " << i << std::endl; */
    av.push_back(store[i]);
  }

  for (int i : av) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return av;
}

int32_t main() {
  clock_t _t = clock();

  /* std::cout << lps("aaaaa", "aaaaa", {2, 3}) << std::endl; */

  for (int i : lps("wfycpc", {2, 2})) {
    std::cout << i << std::endl;
  }

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
