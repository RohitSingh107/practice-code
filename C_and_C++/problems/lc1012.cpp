#include <cstring>
#include <unordered_set>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const long long N = 1e9 + 5;
int dp[N];

/* int repeatedDigits(int n) { */

/*   if (n == 1) { */
/*     return 0; */
/*   } */
/*   if (dp[n] != -1) { */
/*     return dp[n]; */
/*   } */

/*   int tmp = n; */

/*   bool check = false; */
/*   unordered_set<int> s; */
/*   while (tmp != 0) { */
/*     int d = tmp % 10; */
/*     if (s.find(d) != s.end()) { */
/*       check = true; */
/*       break; */
/*     } else { */
/*       s.insert(d); */
/*       tmp = tmp / 10; */
/*     } */
/*   } */

/*   int ans = repeatedDigits(n - 1) + check; */
/*   return dp[n] = ans; */
/* } */

int numDupDigitsAtMostN(int n) {

  /* memset(dp, -1, sizeof(dp)); */
  /* return repeatedDigits(n); */
}

int32_t main() {
  clock_t _t = clock();

  std::cout << numDupDigitsAtMostN(1000) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
