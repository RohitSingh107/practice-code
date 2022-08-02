#include <climits>
#include <cstring>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[305][5005];

int f(int ind, int amount, vector<int> &coins) {

  /* std::cout << "ind is " << ind << " amount is " << amount << std::endl; */

  if (amount == 0) {
    return 1;
  }
  if (ind < 0) {
    return 0;
  }
  if (dp[ind][amount] != -1) {
    return dp[ind][amount];
  }
  int ways = 0;

  for (int i = 0; i <= amount; i += coins[ind]) {
    /* if (amount - i >= 0) */
    ways += f(ind - 1, amount - i, coins);
  }

  return dp[ind][amount] = ways;
}

int change(int amount, vector<int> &coins) {
  memset(dp, -1, sizeof(dp));
  return f(coins.size() - 1, amount, coins);
}

int32_t main() {
  clock_t _t = clock();

  int amount = 5;
  vector<int> coins = {1, 2, 5};

  std::cout << change(amount, coins) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
