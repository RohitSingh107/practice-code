#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        int height;
        Node * left;
        Node * right;
};

int getHeight(Node * n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
void preOrderTraverse(Node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void inOrderTraverse(Node * root){
    if(root == NULL){
        return;
    }
    inOrderTraverse(root->left);
    cout<<root->data<<" ";
    inOrderTraverse(root->right);
}

Node * createNode(int data){
    Node *newnode = new Node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int getBF(Node * n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->left);
}

Node * rightRotate(Node * y){
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->right), getHeight(y->left)) +1;
    x->height = max(getHeight(x->right), getHeight(x->left)) +1;

    return y;
}

Node * leftRotate(Node * x){
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(getHeight(y->right), getHeight(y->left)) +1;
    x->height = max(getHeight(x->right), getHeight(x->left)) +1;

    return y;
}

Node * insert(Node * n, int data){
    if(n == NULL){
        return (createNode(data));
    }
    if(data < n->data){
        n->left = insert(n->left, data);
    }
    else if(data > n->data)
        n->right = insert(n->right, data);
        return n;

    n->height = 1 + max(getHeight(n->right), getHeight(n->left));
    int bf = getBF(n);

    if(bf>1 && data < n->left->data){
        return rightRotate(n);
    }
    
    if(bf<-1 && data > n->right->data){
        return leftRotate(n);
    }

    if(bf>1 && data > n->left->data){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    
    if(bf<-1 && data < n->right->data){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}

int main(){

    Node * root = NULL;
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root,3);

    inOrderTraverse(root);

    return 0;
}
