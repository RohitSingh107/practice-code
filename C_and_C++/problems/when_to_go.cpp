#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int f(vector<vector<int>> &time_table, vector<bool> all_subjects, int i,
      vector<int> &dp) {

  bool all_done = true;
  for (int j = 0; j <= 9; j++) {
    all_done = all_done and all_subjects[j];
  }

  if (all_done) {
    return 0;
  }

  if (i == 5) {
    return 10000000;
  }

  int not_go = f(time_table, all_subjects, i + 1, dp);

  for (auto c : time_table[i]) {

    all_subjects[c] = true;
  }
  int go = f(time_table, all_subjects, i + 1, dp) + 1;

  return dp[i] = min(go, not_go);
}

int32_t main() {
  clock_t _t = clock();

  vector<bool> all_subjects(10);

  vector<int> dp(5, -1);

  vector<vector<int>> time_table = {{8, 4, 1},
                                    {1, 0, 2, 3},
                                    {9, 0, 5, 6, 4, 3},
                                    {1, 3, 4, 2, 5, 4},
                                    {7, 5, 2}};

  std::cout << "Total days to go: " << f(time_table, all_subjects, 0, dp)
            << std::endl;

  std::cout << "dp: ";
  for (int i = 0; i <= 4; i++) {
    std::cout << dp[i] << " ";
  }
  std::cout << std::endl;

  vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday",
                         "Friday"};

  std::cout << "\nStarting with 0 not going" << std::endl;
  int start = 0;
  for (int i = 4; i >= 0; i--) {
    if (dp[i] > start) {
      std::cout << "\nIncreament at i = " << i << std::endl;
      std::cout << "Therefore. going on " << days[i] << std::endl;
      start = dp[i];
    }
  }

  cerr << "\n\nRun Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC
       << " seconds";
  return 0;
}
