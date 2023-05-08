#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// whose sum is equal to the given value
bool hasArrayTwoCandidates(int arr[], int n, int x) {
  // code here
  sort(arr, arr + n);
  int l = 0;
  int h = n - 1;

  while (l < h) {
    // std::cout << "checking " << l << " " << h << std::endl;
    if (arr[l] + arr[h] < x) {

      l += 1;
    } else if (arr[l] + arr[h] > x) {

      h -= 1;

    } else {
      return true;
    }
  }
  return false;
}

int32_t main() {
  clock_t _t = clock();

  int n = 6;
  int x = 16;
  int arr[] = {1, 4, 45, 6, 10, 8};
  std::cout << hasArrayTwoCandidates(arr, n, x) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
