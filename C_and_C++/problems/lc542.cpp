#include <queue>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {

  int m = mat.size();
  int n = mat[0].size();

  vector<vector<int>> new_mat(m, vector<int>(n));

  int drow[] = {-1, 0, 1, 0};
  int dcol[] = {0, 1, 0, -1};

  queue<pair<pair<int, int>, int>> q;
  vector<vector<bool>> visited(m, vector<bool>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 0) {
        q.push({{i, j}, 0});
        visited[i][j] = true;
        new_mat[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto cordinates = q.front().first;
    int dist = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x = cordinates.first + drow[i];
      int y = cordinates.second + dcol[i];

      if (x >= 0 && y >= 0 && x < m && y < n && !visited[x][y]) {
        q.push({{x, y}, dist + 1});
        visited[x][y] = true;
        new_mat[x][y] = dist + 1;
      }
    }
  }

  return new_mat;
}
int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
