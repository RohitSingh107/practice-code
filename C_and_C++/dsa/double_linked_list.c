#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};

void listTraversal(struct Node * head){
    struct Node * ptr = head;
    printf("Elements in lists are: \n");
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != NULL);
}

void reverseTraversal(struct Node * last){
    struct Node * ptr = last;
    printf("Elements in lists are: \n");
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->prev;
    }while(ptr != NULL);
}

void insertFirst(struct Node ** head_ref, int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));

    newnode->data = data;
    (*head_ref)->prev = newnode;
    newnode->next = *head_ref;
    newnode->prev = NULL;
    *head_ref = newnode;
}

void insertEnd(struct Node ** last_ref, int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));

    newnode->data = data;
    (*last_ref)->next = newnode;
    newnode->prev = *last_ref;
    newnode->next = NULL;
    *last_ref = newnode;
}

int popFromLeft(struct Node ** head_ref){
    struct Node * tmp = *head_ref;
    int x = (*head_ref)->data;
    (*head_ref)->next->prev = NULL;
    *head_ref = (*head_ref)->next;
    free(tmp);
    printf("Element %d popped sucessfully\n", x);
    return x;
}

int popFromRight(struct Node ** last_ref){
    struct Node * tmp = *last_ref;
    int x = (*last_ref)->data;
    (*last_ref)->prev->next = NULL;
    *last_ref = (*last_ref)->prev;
    free(tmp);
    printf("Element %d is sucessfully popped\n", x);
    return x;
}


int main(){

    struct Node * head = NULL;
    struct Node * last = NULL;

    struct Node * one = (struct Node *) malloc(sizeof(struct Node));
    struct Node * two = (struct Node *) malloc(sizeof(struct Node));
    struct Node * three = (struct Node *) malloc(sizeof(struct Node));
    struct Node * four = (struct Node *) malloc(sizeof(struct Node));
    
    one->data = 4;
    two->data = 7;
    three->data = 12;
    four->data = 36;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    one->prev = NULL;
    two->prev = one;
    three->prev = two;
    four->prev = three;

    head = one;
    last = four;

    listTraversal(head);
    insertFirst(&head, 88);
    reverseTraversal(last);
    insertEnd(&last, 58);
    listTraversal(head);
    popFromLeft(&head);
    listTraversal(head);
    popFromRight(&last);
    popFromRight(&last);
    listTraversal(head);
    reverseTraversal(last);
    


    return 0;
}