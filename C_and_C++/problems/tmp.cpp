#include <climits>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int jumpT(int i, int n, vector<int> &jumps, vector<int> &dp) {
  // write your code here
  if (i == n - 1) {
    return 0;
  }
  if (i >= n) {
    return 1e9;
  }
  int ans = 1e9;

  for (int j = 1; j <= jumps[i]; j++) {
    ans = min(ans, jumpT(i + j, n, jumps, dp) + 1);
  }

  return ans;
}

int32_t main() {
  clock_t _t = clock();

  int n;
  cin >> n;

  vector<int> jumps(n);

  for (int i = 0; i < n; i++) {
    /* std::cout << "i is " << i << std::endl; */
    cin >> jumps[i];
  }

  vector<int> dp(n + 1, 0);

  int ans = jumpT(0, n, jumps, dp);

  std::cout << ans << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
