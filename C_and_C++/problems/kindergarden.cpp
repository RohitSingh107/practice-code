#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

bool mark[1000];

std::vector<std::vector<int>> allSubSet;

void generateSubset(std::vector<int> &subset, int p, std::vector<int> &nums) {
  if (p == nums.size()) {
    allSubSet.push_back(subset);
    return;
  }
  subset.push_back(nums[p]);
  generateSubset(subset, p + 1, nums);
  subset.pop_back();

  generateSubset(subset, p + 1, nums);
}

int32_t main() {
  clock_t _t = clock();

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> vp(m);
  for (int i = 0; i < m; i++) {
    std::cin >> vp[i].first >> vp[i].second;
  }
  std::vector<int> nums;

  for (int i = 1; i <= n; i++) {
    nums.push_back(i);
  }

  std::vector<int> empty;

  generateSubset(empty, 0, nums);

  int total = allSubSet.size();

  int i = 0;

  for (auto v : allSubSet) {
    i++;
    for (auto p : vp) {
      if (find(v.begin(), v.end(), p.first) != v.end() &&
          find(v.begin(), v.end(), p.second) != v.end() && !mark[i]) {
        mark[i] = 1;
        total--;
      }
    }
  }
  std::cout << total << std::endl;

  std::cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC
            << " seconds";
  return 0;
}
