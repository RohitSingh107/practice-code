#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

void inOrderTraverse(struct Node * root){
    if(root == NULL){
        return;
    }

    inOrderTraverse(root->left);
    printf("%d ", root->data);
    inOrderTraverse(root->right);
}

struct Node * buildNode(int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}

struct Node * insert(struct Node * root, int data){
    
    if(root == NULL){
        return buildNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node * search(struct Node * root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(root->data < data){
        return search(root->right, data);
    }
    else{
        return search(root->left, data);
    }
}

int main(){

    struct Node * root = NULL;

    root = insert(root, 30);
    root = insert(root, 530);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 77);
    root = insert(root, 960);
    root = insert(root, 66);

    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    struct Node * found = search(root, x);
    if(found != NULL){
        printf("Element %d is found!\n", found->data);
    }
    else{
        printf("Element %d is Not found!\n", x);
    }

    printf("Inoder Traversal: ");
    inOrderTraverse(root);

    return 0;
}