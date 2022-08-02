#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

long long wt[105], val[105];

long long dp[105][100005];

long long func(long long ind, long long val_left) {
  if (val_left == 0) {
    return 0;
  }
  if (ind < 0) {
    return 1e15;
  }

  if (dp[ind][val_left] != -1) {
    return dp[ind][val_left];
  }

  // Don't choose
  long long min_w = func(ind - 1, val_left);
  if (val_left - val[ind] >= 0) {
    // Choose it
    min_w = min(min_w, func(ind - 1, val_left - val[ind]) + wt[ind]);
  }
  return dp[ind][val_left] = min_w;
}

int32_t main() {
  clock_t _t = clock();
  memset(dp, -1, sizeof(dp));

  int n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> wt[i] >> val[i];
  }

  /* std::cout << func(n - 1, w) << std::endl; */
  int max_value = 1e5;
  for (int i = max_value; i >= 0; i--) {
    if (func(n - 1, i) <= w) {
      std::cout << i << std::endl;
      break;
    }
  }

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
