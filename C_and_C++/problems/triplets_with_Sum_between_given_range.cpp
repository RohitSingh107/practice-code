#include <algorithm>
#include <string>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int solve(vector<string> &A) {
  sort(A.begin(), A.end());
  int n = A.size();
  int l = 0;
  int r = n - 1;

  while (r - l >= 2) {

    int mid = (r + l) / 2;

    double le = stof(A[l]);
    double re = stof(A[mid]);
    double me = stof(A[r]);

    double sum = le + re + me;

    /* std::cout << "sum is " << sum << std::endl; */

    if (sum <= 1) {
      l++;
    } else if (sum >= 2) {
      r--;
    } else {
      return 1;
    }
  }
  return 0;
}

int32_t main() {
  clock_t _t = clock();

  vector<string> A = {"0.6", "0.7", "0.8", "1.2", "0.4"};
  std::cout << solve(A) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
