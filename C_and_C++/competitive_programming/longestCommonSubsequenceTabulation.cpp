#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int lcs(int x, int y, string s1, string s2) {

  int table[x + 1][y + 1];
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      table[i][j] = 0;
    }
  }

  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      } else {
        table[i][j] = max(table[i][j - 1], table[i - 1][j]);
      }
    }
  }

  return table[x][y];
}
int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
