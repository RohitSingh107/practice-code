#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *left, *right;

};

struct Node * buildNode(int data){
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inOrderTraversal(struct Node * root){

    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    printf(" %d ",root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(struct Node * root){

    if(root == NULL){
        return;
    }
    printf(" %d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct Node * root){

    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %d ",root->data);
}

int main(){

    /*     
                  25
              /        \
             /          \
            /            \
          15             50
         /   \         /   \
        /     \       /     \  
      10      22     35     70
     /  \    / \    / \    /  \
    4   12  8  24  31  44 66  90 

    */

    struct Node * root = buildNode(25);    
    root->left = buildNode(15);
    root->left->left = buildNode(10);
    root->left->left->left = buildNode(4);
    root->left->left->right = buildNode(12);
    root->left->right = buildNode(22);
    root->left->right->left = buildNode(18);
    root->left->right->right = buildNode(24);
    root->right = buildNode(50);
    root->right->left = buildNode(35);
    root->right->left->left = buildNode(31);
    root->right->left->right = buildNode(44);
    root->right->right = buildNode(70);
    root->right->right->left = buildNode(66);
    root->right->right->right = buildNode(90);


    printf("\nInorder Traversal: ");
    inOrderTraversal(root);

    printf("\nPreorder Traversal: ");
    preOrderTraversal(root);

    printf("\nPostorder Traversal: ");
    postOrderTraversal(root);
     
    return 0;
}