#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

long long int c = 0;

long long int dp[1000];

long long int fibonacci(long long int x) {
  c++;
  if (dp[x] != -1) {
    return dp[x];
  }

  long long int fn;
  if (x == 0) {
    return 0;
  } else if (x == 1) {
    return 1;
  }

  else {
    fn = 0LL + fibonacci(x - 1) + fibonacci(x - 2);
  }
  return dp[x] = fn;
}

int32_t main() {
  clock_t _t = clock();
  memset(dp, -1, sizeof(dp));

  long long int a = 50;

  cout << a << "th fibonacci no is " << fibonacci(a);
  std::cout << "\n\nTotal recursive calls with dp: " << c << std::endl;

  cerr << "\n\nRun Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC
       << " seconds";
  return 0;
}
