#include <bits/stdc++.h>
using namespace std;

int jumpT(int i, int n, vector<int> &jumps, vector<int> &dp) {
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 1; j <= jumps[i]; j++) {
      if (i + j <= n) {
        dp[i] = min(dp[i], dp[i + j] + 1);
      }
    }
  }
  return dp[0];
}

int main() {
  int n;
  cin >> n;

  vector<int> jumps(n);
  for (int i = 0; i < n; i++) {
    cin >> jumps[i];
  }
  vector<int> dp(n + 1, 1e9);

  std::cout << jumpT(0, n, jumps, dp) << std::endl;
  return 0;
}
