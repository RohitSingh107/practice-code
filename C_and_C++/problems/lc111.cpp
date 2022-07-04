#include <algorithm>
#include <climits>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int ans = INT_MAX;

void dfs(TreeNode *root, int depth) {

  if (root == nullptr) {
    return;
  }

  if (root->left == nullptr and root->right == nullptr) {
    ans = min(depth, ans);
  }

  dfs(root->left, depth + 1);
  dfs(root->right, depth + 1);
}

class Solution {
public:
  int minDepth(TreeNode *root) {

    if (root == nullptr) {
      return 0;
    }
    dfs(root, 1);
    return ans;
  }
};
int32_t main() { return 0; }
