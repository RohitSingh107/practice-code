#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node * next;
};


void listTraversal(struct Node * head){
    if(head == NULL){
        printf("\nList is empty!\n");
    }
    else{
        struct Node * ptr = head;
        printf("\nElements in lists are: \n");
        do{
            printf(" %d ", ptr->data);
            ptr = ptr->next;
        }while(ptr != head);
        printf("\n");
    }
}

void insertFirst(struct Node ** head_ref, int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));

    newnode->data = data;

    if(*head_ref == NULL){
        newnode->next = newnode;
        *head_ref = newnode;
    }
    else{
        struct Node * p = (*head_ref)->next;
        while(p->next != *head_ref){
            p = p->next;
        }
        p->next = newnode;
        newnode->next = *head_ref;
        *head_ref = newnode;
    }
}

void insertEnd(struct Node *head, int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));

    newnode->data = data;
    if(head == NULL){
        printf("List is empty, insert from beginning\n");
    }
    else{

    
        struct Node * p = head->next;

        newnode->data = data;

        while(p->next != head){
            p = p->next;
        }
        p->next = newnode;
        newnode->next = head;
    }
}

int popFromLeft(struct Node ** head_ref){

    struct Node * tmp = (*head_ref)->next;

    if(tmp == *head_ref){
        free(tmp);
        *head_ref = NULL;
    }
    else{

        while(tmp->next != *head_ref){
            tmp = tmp->next;
        }

        tmp->next = (*head_ref)->next;
        tmp = *head_ref;
        *head_ref = tmp->next;
        int x = tmp->data;
        free(tmp);
        return x;
    }

}

int popFromRight(struct Node ** head_ref){

    struct Node * tmp = (*head_ref)->next;

    if(tmp == *head_ref){
        free(tmp);
        *head_ref = NULL;
    }
    else{
        while(tmp->next->next != *head_ref){
            tmp = tmp->next;
        }
        struct Node * ptr = tmp->next;
        tmp->next = *head_ref;
        // printf("data is %d\n", tmp->data);
        // printf("data is %d\n", tmp->next->data);
        // printf("data is %d\n", ptr->data);

        int x = ptr->data;
        free(ptr);
        return x;
    }

}



int main(){

    struct Node * head = NULL;

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
    four->next = one;

    head = one;


    // display_node(two->next);
    // display_node(four->next);
    
    listTraversal(head);
    insertFirst(&head, 25);
    listTraversal(head);
    insertEnd(head, 415);
    listTraversal(head);
    popFromLeft(&head);
    popFromLeft(&head);
    listTraversal(head);
    popFromRight(&head);
    popFromLeft(&head);
    listTraversal(head);
    popFromLeft(&head);
    popFromRight(&head);
    listTraversal(head);

    insertFirst(&head, 99);
    listTraversal(head);

    // if(head == NULL){
    //     printf("NULL");
    // }

    // printf("data is %d\n", head->data);
    // printf("data is %d\n", head->next->data);


    return 0;
}