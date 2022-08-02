#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[10005];

int dp2d[15][10005];

int f(int amount, vector<int> &coins) {
  if (dp[amount] != -1)
    return dp[amount];
  if (amount == 0) {
    return 0;
  }
  int ans = INT_MAX;
  for (auto coin : coins) {
    if (amount - coin >= 0) {
      ans = min(ans + 0LL, f(amount - coin, coins) + 1LL);
    }
  }

  return dp[amount] = ans;
}

/* int f2(int ind, int amount_remaining, vector<int> coins) { */
/*   /1* std::cout << "ind is " << ind << " remaing amound_remaining is " *1/ */
/*   /1* << amount_remaining << std::endl; *1/ */
/*   if (amount_remaining == 0) { */
/*     return 0; */
/*   } */

/*   if (ind < 0) { */
/*     return INT_MAX; */
/*   } */

/*   if (dp2d[ind][amount_remaining] != -1) { */
/*     return dp2d[ind][amount_remaining]; */
/*   } */

/*   int ans = INT_MAX; */

/*   for (int i = 0; i <= amount_remaining; i += coins[ind]) { */
/*     /1* for (int i = 0; i * coins[ind] <= amount_remaining; i++) { *1/ */
/*     /1* std::cout << "ind is " << ind << " i is " << i << std::endl; *1/ */
/*     /1* ans = min(ans + 0LL, f2(ind - 1, amount_remaining - i * coins[ind],
 */
/*      * coins) + (i * 1LL)); *1/ */
/*     ans = min(ans + 0LL, f2(ind - 1, amount_remaining - i, coins) + */
/*                              ((i / coins[ind]) * 1LL)); */
/*   } */

/*   return dp2d[ind][amount_remaining] = ans; */
/* } */

int coinChange(vector<int> &coins, int amount) {

  /* memset(dp, -1, sizeof(dp)); */
  memset(dp2d, -1, sizeof(dp2d));
  long long ans = f(amount, coins);

  if (ans >= INT_MAX) {
    return -1;
  }

  return ans;
}

int32_t main() {
  clock_t _t = clock();

  vector<int> coins = {1, 7, 5};
  int amount = 18;

  /* vector<int> coins = {2}; */
  /* int amount = 5; */
  /* vector<int> coins = {1}; */
  /* int amount = 0; */
  std::cout << coinChange(coins, amount) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
