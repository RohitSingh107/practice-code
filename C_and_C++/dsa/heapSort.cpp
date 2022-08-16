#include <functional>
#include <future>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool cmpG(int x, int y) { return x > y; }
bool cmpL(int x, int y) { return x < y; }

void heapify(int arr[], int n, int i, function<bool(int, int)> cmp) {

  int mx = i;

  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && cmp(arr[l], arr[mx])) {
    mx = l;
  }

  if (r < n && cmp(arr[r], arr[mx])) {
    mx = r;
  }

  if (mx != i) {
    swap(arr[i], arr[mx]);
    heapify(arr, n, mx, cmp);
  }
}

void heapSort(int arr[], int n, function<bool(int, int)> cmp) {

  // Form max heap
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, cmp);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);

    heapify(arr, i, 0, cmp);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int32_t main() {
  clock_t _t = clock();

  int arr[] = {4, 9, 3, 5, 4, 6, 4, 2, 15, 13, 14, 12};
  int n = *(&arr + 1) - arr;

  printArray(arr, n);

  heapSort(arr, n, cmpL);

  printArray(arr, n);

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
