#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, vector<vector<bool>> &visited,
         vector<vector<char>> &board) {

  if (i < 0 || j < 0 || i == visited.size() || j == visited[0].size() ||
      visited[i][j] || board[i][j] != 'O') {
    return;
  }
  visited[i][j] = true;

  dfs(i - 1, j, visited, board);
  dfs(i, j + 1, visited, board);
  dfs(i, j - 1, visited, board);
  dfs(i + 1, j, visited, board);
}

void solve(vector<vector<char>> &board) {

  int m = board.size();
  int n = board[0].size();

  vector<vector<bool>> visited(m, vector<bool>(n));

  for (int i = 0; i < m; i++) {
    if (board[i][0] == 'O' && !visited[i][0]) {
      dfs(i, 0, visited, board);
    }
    if (board[i][n - 1] == 'O' && !visited[i][n - 1]) {
      dfs(i, n - 1, visited, board);
    }
  }

  for (int j = 0; j < n; j++) {
    if (board[0][j] == 'O' && !visited[0][j]) {
      dfs(0, j, visited, board);
    }
    if (board[m - 1][j] == 'O' && !visited[m - 1][j]) {
      dfs(m - 1, j, visited, board);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j]) {
        board[i][j] = 'O';
      } else {
        board[i][j] = 'X';
      }
    }
  }
}

int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
