#include <algorithm>
/* #include <vector> */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") */
/* #pragma GCC optimize("unroll-loops") */
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int dp[1005];

int maximuxValue(int remaiming_length, vector<int> price) {

  /* if (remaiming_length < 0) { */
  /*   return 0; */
  /* } */

  if (dp[remaiming_length] != -1) {
    return dp[remaiming_length];
  }

  int maxVal = 0;

  for (int i = 1; i <= price.size(); i++) {
    if (remaiming_length - i >= 0)
      maxVal =
          max(maxVal, maximuxValue(remaiming_length - i, price) + price[i - 1]);
  }

  return dp[remaiming_length] = maxVal;
}

int cutRod(int price[], int n) {
  vector<int> prices(price, price + n);

  memset(dp, -1, sizeof(dp));

  return maximuxValue(n, prices);
}

int32_t main() {
  clock_t _t = clock();

  int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

  std::cout << cutRod(price, 8) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
