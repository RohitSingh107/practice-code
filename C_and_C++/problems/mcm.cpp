#include <bits/stdc++.h>

using namespace std;

int matrixMultiplication(int N, int arr[]) {
  vector<vector<int>> dp(N, vector<int>(N, 0));
  for (int i = N - 1; i >= 1; i--) {
    for (int j = i + 1; j < N; j++) {
      if (i == j)
        continue;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                                     (arr[i - 1] * arr[k] * arr[j]));
      }
    }
  }
  return dp[1][N - 1];
}

int32_t main() {
  int N = 5;
  int arr[] = {40, 20, 30, 10, 30};
  std::cout << matrixMultiplication(N, arr) << std::endl;
}
