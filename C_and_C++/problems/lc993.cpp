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

int findDepth(TreeNode *root, int digit, int &parent, int height) {
  if (root == nullptr) {
    return 0;
  }

  if (root->val == digit) {
    return height;
  }

  parent = root->val;

  int left = findDepth(root->left, digit, parent, height + 1);

  if (left) {
    return left;
  }

  parent = root->val;
  int right = findDepth(root->right, digit, parent, height + 1);

  return right;
}

bool isCousins(TreeNode *root, int x, int y) {

  if (root->val == x || root->val == y) {
    return false;
  }

  int xparent = -1;
  int xdepth = findDepth(root, x, xparent, 0);

  int yparent = -1;
  int ydepth = findDepth(root, y, yparent, 0);

  if (xparent != yparent && xdepth == ydepth) {
    return true;
  }

  return false;
}

int32_t main() { return 0; }
