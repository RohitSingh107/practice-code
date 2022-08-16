#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A) {

  int n = A.size();
  int tmp = -1;

  for (int i = 1; i < n; i++) {

    if (A[i] != 0) {
      if (A[i - 1] == 0) {

        if (i < n) {
          swap(A[i], A[tmp + 1]);

          tmp++;
          if (tmp == 9) {
          }
        }
      }
    } else {
      if (A[i - 1] != 0) {
        tmp = i - 1;
      }
    }
  }
  return A;
}

int32_t main() {
  clock_t _t = clock();

  vector<int> A = {2, 8, 10, 1, 1, 9, 3, 0, 6, 0, 9, 6, 2, 0, 3, 5, 6, 0};

  for (auto i : solve(A)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
