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
    cout << "Enter left child of " << front->data << ": ";
    cin >> leftdata;
    if (leftdata != -1) {
      BinaryTreeNode<int> *leftchild = new BinaryTreeNode<int>(leftdata);
      pendingnodes.push(leftchild);
      front->left = leftchild;
    }
    int rightdata;
    cout << "enter the right child of " << front->data << ": ";
    cin >> rightdata;
    if (rightdata != -1) {
      BinaryTreeNode<int> *rightchild = new BinaryTreeNode<int>(rightdata);
      pendingnodes.push(rightchild);
      front->right = rightchild;
    }
  }
  std::cout << "Reached here" << std::endl;
  return root;
}

void print(BinaryTreeNode<int> *root) {
  queue<pair<BinaryTreeNode<int> *, int>> pendingnodes;
  pendingnodes.push({root, 0});

  int prev_lev = -1;

  while (!pendingnodes.empty()) {
    BinaryTreeNode<int> *front = pendingnodes.front().first;
    int level = pendingnodes.front().second;
    pendingnodes.pop();
    if (front == NULL) {
      continue;
    }

    if (level == prev_lev) {
      std::cout << " ";
    } else {
      std::cout << std::endl;
    }

    cout << front->data;

    prev_lev = level;

    pendingnodes.push({front->left, level + 1});
    pendingnodes.push({front->right, level + 1});
  }
  std::cout << endl << std::endl;
}

int main() {
  BinaryTreeNode<int> *root = input();
  print(root);

  return 0;
}
