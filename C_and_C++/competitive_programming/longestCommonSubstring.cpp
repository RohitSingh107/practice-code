// Not optimized
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
/* int dp[100][100][100]; */
int c = 0;
int longestCommonSubstring(int i, int j, int count, string &s1, string &s2,
                           unordered_map<string, int> &m) {

  c++;
  /* std::cout << "i is " << i << " j is " << j << " count is " << count */
  /* << std::endl; */
  if (i < 0 || j < 0) {
    return count;
  }

  string key = to_string(i) + " " + to_string(j) + " " + to_string(count);

  if (m[key] != 0) {
    return m[key];
  }

  int ans = count;

  if (s1[i] == s2[j]) {
    ans = max(ans, longestCommonSubstring(i - 1, j - 1, count + 1, s1, s2, m));
  }

  ans = max(ans, longestCommonSubstring(i, j - 1, 0, s1, s2, m));
  ans = max(ans, longestCommonSubstring(i - 1, j, 0, s1, s2, m));

  /* m.insert({key, ans}); */
  m[key] = ans;
  std::cout << key << " | " << ans << std::endl;
  std::cout << "ans is " << m[key] << std::endl;
  return m[key];

  /* return m[key] = ans; */
}

int32_t main() {
  clock_t _t = clock();

  unordered_map<string, int> dp;

  string s1 = "wqabsrmpmo";
  string s2 = "qbsrmpcnp";

  /* string s1 = "p"; */
  /* string s2 = "p"; */
  std::cout << longestCommonSubstring(s1.size() - 1, s2.size() - 1, 0, s1, s2,
                                      dp)
            << std::endl;
  std::cout << "\nTotal recursive calls with dp:  " << c << std::endl;

  cerr << "\n\nRun Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC
       << " seconds";
  return 0;
}
