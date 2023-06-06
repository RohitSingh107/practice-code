#include <climits>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {

  if (i > j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ans = INT_MAX;
  for (int k = i; k <= j; k++) {
    int cost = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp) +
               f(k + 1, j, cuts, dp);
    ans = min(cost, ans);
  }
  return dp[i][j] = ans;
}

int minCost(int n, vector<int> &cuts) {

  int l = cuts.size();
  cuts.insert(cuts.begin(), 0);
  cuts.push_back(n);
  sort(cuts.begin(), cuts.end());
  vector<vector<int>> dp(l + 2, vector<int>(l + 2, -1));

  return f(1, l, cuts, dp);
}

int32_t main() {
  clock_t _t = clock();

  int n = 7;
  vector<int> cuts = {1, 3, 4, 5};

  std::cout << "ans is " << minCost(n, cuts) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
