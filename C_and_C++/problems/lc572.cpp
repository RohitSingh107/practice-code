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

class Solution {
public:

    void preOrder(TreeNode* root, vector<int>& container){
        if(root == nullptr){
            return;
        }
        preOrder(root->left, container);
        container.push_back(root->val);
        preOrder(root->right, container);
    }

    bool dfs(TreeNode* root, int val, vector<int>& stpreOrder){
        
        if(root == nullptr){
            return false;
        }

        if(root->val == val){
            vector<int> tmp;
            tmp.clear();
            preOrder(root, tmp);
            
            if(stpreOrder == tmp){
                return true;
            }
       
        }

        return dfs(root->left, val, stpreOrder) || dfs(root->right, val, stpreOrder);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> subTreePreOrder;
		preOrder(subRoot, subTreePreOrder);
		return dfs(root, subRoot->val, subTreePreOrder);
    }
};

int32_t main(){
	
	return 0;
}

