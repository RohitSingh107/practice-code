#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(vector<vector<int>> &A) {

  int m = A.size();
  int n = A[0].size();

  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= n; j++) {
      std::cout << "here 1 " << i << " " << j << std::endl;
      swap(A[i - 1][j - 1], A[j - 1][i - 1]);
      std::cout << "here 2 " << i << " " << j << std::endl;
    }
  }
  return A;
}

int32_t main() {
  clock_t _t = clock();

  vector<vector<int>> matrix = {{1, 0}, {0, 1}};

  for (auto v : solve(matrix)) {
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
