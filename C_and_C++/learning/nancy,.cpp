#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T> class TreeNode {
public:
  T data;
  vector<TreeNode<T> *> children;

  TreeNode(T data) { this->data = data; }

  ~TreeNode() {
    for (int i = 0; i < children.size(); i++) {
      delete children[i];
    }
  }
};

TreeNode<int> *takeInputLevelWise() {
  int rootData;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);

  queue<TreeNode<int> *> pendingNodes;

  pendingNodes.push(root);
  while (pendingNodes.size() != 0) {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int numChild;
    cin >> numChild;
    for (int i = 0; i < numChild; i++) {
      int childData;
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }

  return root;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root) {
  // if(root == NULL){
  //     return NULL;
  // }
  // Pair res = maxNode(root);
  // return res.node;
  if (root == NULL)
    return NULL;
  int maxsum = root->data;

  TreeNode<int> *root1 = root;

  if (root->children.size() == 0) {
    return root1;
  }
  TreeNode<int> *a = root;
  for (int i = 0; i < root->children.size(); i++) {
    a = maxSumNode(root->children[i]);
  }
  int sum = root->data;
  for (int i = 0; i < root->children.size(); i++) {

    if (a->children.size() == 0 || a->children.size() <= i) {
      continue;
    }
    sum += a->children[i]->data;
  }

  if (sum > maxsum) {
    maxsum = sum;
    root1 = a;
  }
  return root1;
}

int main() {
  TreeNode<int> *root = takeInputLevelWise();

  TreeNode<int> *ans = maxSumNode(root);

  if (ans != NULL) {
    cout << ans->data;
  }
}
