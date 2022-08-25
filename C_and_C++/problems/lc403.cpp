// https://leetcode.com/problems/frog-jump/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[2100][2100];

int frogJump(int pos, int k, int n, vector<int> &stones) {

  if (pos == n - 1) {
    return true;
  }
  if (dp[pos][k] != -1) {
    return dp[pos][k];
  }

  int ja = false, jb = false, jc = false;

  int x = -1;
  if (k - 1 > 0) {
    x = stones[pos] + k - 1;
    int i = lower_bound(stones.begin(), stones.end(), x) - stones.begin();
    if (i != n) {
      if (stones[i] == x)
        ja = frogJump(i, k - 1, n, stones);
    }
  }

  x = stones[pos] + k;
  int i = lower_bound(stones.begin(), stones.end(), x) - stones.begin();
  if (i != n) {
    if (stones[i] == x)
      jb = frogJump(i, k, n, stones);
  }

  x = stones[pos] + k + 1;
  i = lower_bound(stones.begin(), stones.end(), x) - stones.begin();
  if (i != n) {
    if (stones[i] == x)
      jc = frogJump(i, k + 1, n, stones);
  }

  return dp[pos][k] = ja || jb || jc;
}

bool canCross(vector<int> &stones) {
  memset(dp, -1, sizeof(dp));
  int n = stones.size();
  return frogJump(1, 1, n, stones);
}

int32_t main() {
  clock_t _t = clock();
  vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  /* vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11}; */

  std::cout << canCross(stones) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
