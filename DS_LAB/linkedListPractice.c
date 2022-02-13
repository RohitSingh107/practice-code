#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void display(struct Node * head){
    struct Node * tmp = head;
    printf("List is \n");
    while(tmp != NULL){
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

struct Node * buildNode(int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertAtIndex(struct Node **head_ref, int index, int data){
    if(*head_ref == NULL){
        *head_ref = buildNode(data);
        return;
    }
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;

    if(index ==0){
        newnode->next = (*head_ref);
        *head_ref = newnode;
        return;
    }

    struct Node * tmp = *head_ref;
    for(int i = 0; i< index-1 && tmp->next != NULL; i++){
        //printf("index is %d\n", i);
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
    //printf("Daat is %d\n", tmp->data);
}

void deleteAtIndex(struct Node **head_ref, int index){
    struct Node * tmp = *head_ref;
    struct Node * del;
    if(index == 0){
        *head_ref = (*head_ref)->next;
        free(tmp);
        return;
    }

    for(int i = 0; i< index-1 && tmp->next != NULL; i++){
        //printf("index is %d\n", i);
        tmp = tmp->next;
    }
    del = tmp->next;
    tmp->next = tmp->next->next;
    free(del);
}


int main(){

    struct Node * one = buildNode(7);
    struct Node * head = one;

    insertAtIndex(&head, 1, 5);
    insertAtIndex(&head, 2,35);
    insertAtIndex(&head, 0,6);

    //printf("Data is %d\n", head->next->next->data);

    display(head);
    insertAtIndex(&head, 1,66);
    display(head);
    insertAtIndex(&head, 2,69);
    display(head);
    insertAtIndex(&head, 3,129);
    display(head);
    insertAtIndex(&head, 6,19);
    display(head);
    insertAtIndex(&head, 8,78);
    display(head);
    deleteAtIndex(&head, 0);
    display(head);
    deleteAtIndex(&head, 2);
    display(head);
    deleteAtIndex(&head, 4);
    display(head);


    return 0;

}
