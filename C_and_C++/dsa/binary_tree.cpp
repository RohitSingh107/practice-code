#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * left;
        Node * right;
};

Node * createNode(int data){
    Node *newnode = new Node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inOrderTraverse(Node * root){
    if(root == NULL){
        return;
    }
    inOrderTraverse(root->left);
    cout<<root->data<<" ";
    inOrderTraverse(root->right);
}
void preOrderTraverse(Node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}
void postOrderTraverse(Node * root){
    if(root == NULL){
        return;
    }
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout<<root->data<<" ";
}

bool isBST(Node * root){
    static Node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }

        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

// Iterative BST insertion
Node* search(Node * root, int data){
    if(root == NULL){
        return root;
    }
    else if(root->data == data){
        return root;
    }
    else if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
} 
Node* IterSearch(Node * root, int data){
    if(root == NULL){
        return NULL;
    }
    while(root != NULL){
        if(root->data == data){
            return root;
        }
        else if(data < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
} 

void insert(Node * root, int data){
    Node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(data == root->data){
            return;
        }
        else if(data < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    Node * newnode = createNode(data);
    if( data < prev->data){
        prev->left = newnode;
    }
    else{
        prev->right = newnode;
    }
}

Node * inOrdPred(Node * root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node * deleteNode(Node * root, int value){
    Node * iPre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        root->left =  deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right =  deleteNode(root->right, value);
    }
    else{
        iPre = inOrdPred(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main(){

    
    Node *p = createNode(14);
    Node *p1 = createNode(5);
    Node *p2 = createNode(25);

    Node *p3 = createNode(1);
    Node *p4 = createNode(7);

    Node *p5 = createNode(17);
    Node *p6 = createNode(30);

    p->left= p1;
    p->right= p2;

    p1->left= p3;
    p1->right= p4;

    p2->left= p5;
    p2->right= p6;

    inOrderTraverse(p);
    cout<<endl;
    preOrderTraverse(p);
    cout<<endl;
    postOrderTraverse(p);
    cout<<endl;

    cout<<isBST(p)<<endl;

    Node * found = search(p, 5);
    cout<<((found != NULL) ? found->data : -1)<<endl;

    Node * foundIter = IterSearch(p, 33);
    cout<<((foundIter != NULL) ? foundIter->data : -1)<<endl;

    inOrderTraverse(p);
    cout<<endl;
    insert(p, 10);
    inOrderTraverse(p);
    cout<<endl;
    deleteNode(p, 7);
    inOrderTraverse(p);
    cout<<endl;

    return 0;
}
