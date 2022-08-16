#include <algorithm>
#include <cmath>
#include <complex>
#include <valarray>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int K;

bool cmp(int a, int b) {
  if (abs(K - a) != abs(K - b)) {
    return abs(K - a) < abs(K - b);
  } else {
    return abs(K - a) != abs(K - b);
  }
}

void sortABS(int A[], int N, int k) {

  K = k;

  /* sort(A, A + N, cmp); */
  stable_sort(A, A + N, cmp);
  for (int i = 0; i < N; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

int32_t main() {
  clock_t _t = clock();

  /* int N = 5, K = 7; */
  /* int arr[] = {10, 5, 3, 9, 2}; */

  int N = 5, K = 6;
  int arr[] = {1, 2, 3, 4, 5};

  sortABS(arr, N, K);

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
