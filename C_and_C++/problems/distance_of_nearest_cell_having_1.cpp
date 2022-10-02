#include <queue>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> nearest(vector<vector<int>> grid) {

  int m = grid.size();
  int n = grid[0].size();

  int drow[] = {-1, 0, 1, 0};
  int dcol[] = {0, 1, 0, -1};

  vector<vector<bool>> visited(m, vector<bool>(n, 0));
  vector<vector<int>> dist(m, vector<int>(n, 0));

  queue<pair<pair<int, int>, int>> q;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        visited[i][j] = true;
        dist[i][j] = 0;
        q.push({{i, j}, 0});
      }
    }
  }

  while (!q.empty()) {
    auto f = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int row = drow[i] + f.first.first;
      int col = dcol[i] + f.first.second;
      int d = f.second;

      if (row >= 0 && col >= 0 && row < m && col < n && !visited[row][col]) {
        dist[row][col] = d + 1;
        visited[row][col] = true;
        q.push({{row, col}, d + 1});
      }
    }
  }

  return dist;
}

int32_t main() {
  clock_t _t = clock();

  vector<vector<int>> grid = {{1, 0, 1}, {1, 1, 0}, {1, 0, 0}};

  for (auto v : nearest(grid)) {
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
