#include <algorithm>
#include <complex>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int dfs(TreeNode* root){
	if(root == nullptr){
		return 0;
	}

	int lh = dfs(root->left);

	int rh = dfs(root->right);

	int height = -1;
	if(abs(lh - rh) <= 1 and lh != -1 and rh != -1){
		height = 1 + max(lh, rh);
	}

	return height;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {

		if(dfs(root) != -1){
			return true;
		}

		return false;
    }
};

int32_t main(){
	
	

	return 0;
}

