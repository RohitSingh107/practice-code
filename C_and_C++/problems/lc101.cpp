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

bool mirror(TreeNode* rootl, TreeNode* roolr){
	if(rootl == nullptr and roolr == nullptr){
		return true;
	}
	if(roolr == nullptr || rootl == nullptr){
		return false;
	}

	return (rootl->val == roolr->val) && mirror(rootl->left, roolr->right) && mirror(roolr->left, rootl->right);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		return mirror(root->left, root->right);
    }
};


int32_t main(){
	
	

	return 0;
}

