#include <algorithm>
#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

long long int wt[105], val[105];

long long int dp[105][100005];

long long int func(long long int ind, long long int wt_left) {
  if (wt_left == 0) {
    return 0;
  }
  if (ind < 0) {
    return 0;
  }
  if (dp[ind][wt_left] != -1) {
    return dp[ind][wt_left];
  }

  long long int max_value = 0;

  max_value = max(max_value, func(ind - 1, wt_left));
  if (wt_left - wt[ind] >= 0) {
    max_value = max(max_value, func(ind - 1, wt_left - wt[ind]) + val[ind]);
  }

  return dp[ind][wt_left] = max_value;
}

int32_t main() {
  clock_t _t = clock();
  memset(dp, -1, sizeof(dp));

  int n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> wt[i] >> val[i];
  }

  std::cout << func(n - 1, w) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
