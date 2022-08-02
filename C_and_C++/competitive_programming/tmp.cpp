#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

void helper(vector<int> &nums, int size, int i, vector<int> curr,
            vector<vector<int>> &ans) {
  for (int j = i; j < nums.size(); j++) {
    if (j > i && nums[i - 1] == nums[i])
      continue;
    ans.push_back(curr);
    return;
  }
  helper(nums, size, i + 1, curr, ans);
  // include
  curr.push_back(nums[i]);
  helper(nums, size, i + 1, curr, ans);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;

  helper(nums, nums.size(), 0, {}, ans);

  // To avoid duplicate elements in array
  /* if(nums.size()!=1){ */
  /* sort(ans.begin(),ans.end()); */
  /* for(int i=0;i<ans.size()-1;i++){ */
  /*     if(ans[i]==ans[i+1]){ */
  /*         ans.erase(ans.begin()+i); */
  /*     } */
  /* } */
  /* } */
  return ans;
}

int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
