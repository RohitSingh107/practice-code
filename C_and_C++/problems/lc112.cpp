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

bool dfs(TreeNode *root, int targetSum, int sum) {
  if (root == nullptr) {
    return false;
  }

  if (root->left == nullptr and root->right == nullptr) {
    if (sum + root->val == targetSum) {
      return true;
    } else {
      return false;
    }
  }

  return dfs(root->left, targetSum, sum + root->val) ||
         dfs(root->right, targetSum, sum + root->val);
}

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    return dfs(root, targetSum, 0);
  }
};

int32_t main() { return 0; }
