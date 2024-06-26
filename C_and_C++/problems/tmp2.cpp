#include <bits/stdc++.h>

using namespace std;
template <typename T> class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode<int> *left;
  BinaryTreeNode<int> *right;
  BinaryTreeNode(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};
BinaryTreeNode<int> *input() {
  int rootdata;
  cout << "Enter root data ";
  cin >> rootdata;
  if (rootdata == -1)
    return NULL;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
  queue<BinaryTreeNode<int> *> pendingnodes;
  pendingnodes.push(root);
  while (!pendingnodes.empty()) {
    BinaryTreeNode<int> *front = pendingnodes.front();
    pendingnodes.pop();
    int leftdata;
    cout << "Enter left child of " << front->data;
    cin >> leftdata;
    if (leftdata != -1) {
      BinaryTreeNode<int> *leftchild = new BinaryTreeNode<int>(leftdata);
      pendingnodes.push(leftchild);
      front->left = leftchild;
    }
    int rightdata;
    cout << "enter the right child of " << front->data;
    cin >> rightdata;
    if (rightdata != -1) {
      BinaryTreeNode<int> *rightchild = new BinaryTreeNode<int>(rightdata);
      pendingnodes.push(rightchild);
      front->right = rightchild;
    }
  }
  return root;
}
void print(BinaryTreeNode<int> *root) {
  queue<BinaryTreeNode<int> *> pendingnodes;
  pendingnodes.push(root);
  pendingnodes.push(NULL);
  while (!pendingnodes.empty()) {
    BinaryTreeNode<int> *front = pendingnodes.front();
    pendingnodes.pop();
    if (front == NULL && pendingnodes.empty())
      break;
    else if (front == NULL && !pendingnodes.empty()) {
      cout << endl;
      pendingnodes.push(NULL);
      continue;
    }
    cout << front->data << " ";
    pendingnodes.push(front->left);
    pendingnodes.push(front->right);
  }
}
int main() {
  BinaryTreeNode<int> *root = input();
  print(root);

  return 0;
}
