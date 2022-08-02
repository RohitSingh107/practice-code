/* #include <algorithm> */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") */
/* #pragma GCC optimize("unroll-loops") */
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int plan[100005][3];

int dp[100005][3];

int happiness(int day, int activity) {

  if (day < 0) {
    return 0;
  }
  if (dp[day][activity] != -1) {
    return dp[day][activity];
  }

  int max_val = 0;

  for (int i = 0; i <= 2; i++) {
    if (i != activity) {

      max_val = max(max_val, happiness(day - 1, i) + plan[day][activity]);
    }
  }

  return dp[day][activity] = max_val;
}

/* 10 40 70 */
/* 20 50 80 */
/* 30 60 90 */

int32_t main() {
  clock_t _t = clock();

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> plan[i][0] >> plan[i][1] >> plan[i][2];
  }

  memset(dp, -1, sizeof(dp));
  int ans = 0;
  ans = max(ans, happiness(n - 1, 0));
  ans = max(ans, happiness(n - 1, 1));
  ans = max(ans, happiness(n - 1, 2));

  std::cout << ans << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
