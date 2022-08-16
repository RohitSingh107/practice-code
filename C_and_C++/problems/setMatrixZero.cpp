#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &A) {

  unordered_map<int, bool> r;
  unordered_map<int, bool> c;

  int m = A.size();
  int n = A[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] == 0) {
        if (i == 0 and j == 1) {
          std::cout << " values  " << r[i] << " " << c[i] << std::endl;
        }
        r[i] = true;
        c[j] = true;
      }
      if (i == 0 and j == 1) {
        std::cout << " values  " << r[i] << " " << c[i] << std::endl;
      }
    }
  }
  std::cout << "here" << std::endl;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << "here " << i << " " << j << " " << r[i] << " " << c[j] << endl;
      if (r[i] || c[j]) {
        A[i][j] = 0;
      }
    }
  }
}

int32_t main() {
  clock_t _t = clock();

  /* vector<vector<int>> A = {{0, 0}, {1, 0}}; */
  vector<vector<int>> A = {{0, 0}, {1, 1}};
  setZeroes(A);
  for (auto v : A) {
    for (int i : v) {
      std::cout << i;
    }
    std::cout << std::endl;
  }

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
