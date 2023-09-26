
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    int mi = 0;
    int mj = 0;
    int mp = 0;
    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][j] != -1) {
          ans = max(ans, dp[i][j]);
        } else {
          ans = max(ans, lip(i, j, matrix, m, n, dp));
        }

        if (dp[i][j] > mp) {
          mp = dp[i][j];
          mi = i;
          mj = j;
        }
      }
    }

    // Construct the path
    vector<int> path;
    while (mi >= 0 && mj >= 0 && mi < m && mj < n) {
      path.push_back(matrix[mi][mj]);

      if (mi > 0 && dp[mi][mj] - dp[mi - 1][mj] == 1) {
        mi -= 1;
      } else if (mj > 0 && dp[mi][mj] - dp[mi][mj - 1] == 1) {
        mj -= 1;
      } else if (mj < n - 1 && dp[mi][mj] - dp[mi][mj + 1] == 1) {
        mj += 1;
      } else if (mi < m - 1 && dp[mi][mj] - dp[mi + 1][mj] == 1) {
        mi += 1;
      } else {
        break;
      }
    }

    cout << "path is ";
    for (int i = 0; i < path.size(); ++i) {
      cout << path[i] << " ";
    }
    cout << endl;

    cout << "length is " << ans << endl;
    return ans;
  }

private:
  int lip(int i, int j, vector<vector<int>> &matrix, int m, int n,
          vector<vector<int>> &dp) {
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int ans = 0;

    if (i > 0 && matrix[i - 1][j] - matrix[i][j] == 1) {
      ans = max(ans, lip(i - 1, j, matrix, m, n, dp));
    }

    if (j > 0 && matrix[i][j - 1] - matrix[i][j] == 1) {
      ans = max(ans, lip(i, j - 1, matrix, m, n, dp));
    }

    if (j <= n - 2 && matrix[i][j + 1] - matrix[i][j] == 1) {
      ans = max(ans, lip(i, j + 1, matrix, m, n, dp));
    }

    if (i <= m - 2 && matrix[i + 1][j] - matrix[i][j] == 1) {
      ans = max(ans, lip(i + 1, j, matrix, m, n, dp));
    }

    dp[i][j] = ans + 1; // 1 for this current element
    return dp[i][j];
  }
};

int main() {
  vector<vector<int>> matrix = {{8, 9, 8}, {7, 4, 3}, {6, 5, 2}};
  // vector<vector<int>> matrix = {{8, 5, 8}, {7, 4, 4}, {2, 5, 2}};
  Solution solution;
  cout << solution.longestIncreasingPath(matrix) << endl;
  return 0;
}
