#include <climits>
#include <cstring>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int func1(int ind, int amount, vector<int> &coins) {

  if (amount == 0)
    return 1;
  if (ind < 0)
    return 0;

  int ways = 0;

  for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind]) {
    ways += func1(ind - 1, amount - coin_amount, coins);
  }

  return ways;
}

int change(int amount, vector<int> &coins) {
  /* return f(coins.size() - 1, amount, coins); */
  return func1(coins.size() - 1, amount, coins);
}

int32_t main() {
  clock_t _t = clock();

  int amount = 5;
  vector<int> coins = {1, 2, 5};

  std::cout << change(amount, coins) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
