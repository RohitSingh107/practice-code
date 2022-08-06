#include <algorithm>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int taps(int i, int status, vector<int> &ranges, vector<bool> &check) {

  if (i == 0) {
    if (check[i]) {
      return 0;
    } else {
      return 1;
    }
  }

  int ans = INT_MAX;

  ans = min(ans, taps(i - 1, 0, ranges, check));

  check[i] = true;

  for (int j = i - ranges[i]; j <= i + ranges[i]; j++) {
    if (j >= 0)
      check[j] = true;
  }
  ans = min(ans, taps(i - 1, 1, ranges, check) + 1);

  return ans;
}

int minTaps(int n, vector<int> &ranges) {
  int ans = INT_MAX;

  vector<bool> check(105);

  ans = min(ans, taps(n - 1, 0, ranges, check));
  check.clear();
  ans = min(ans, taps(n - 1, 1, ranges, check));
  return ans;
}

int32_t main() {
  clock_t _t = clock();

  vector<int> ranges = {3, 4, 1, 1, 0, 0};
  std::cout << minTaps(4, ranges) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
