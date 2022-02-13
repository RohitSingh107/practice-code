#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node * next;
};

void display(struct Node * head){
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
        printf(" %d\n\n", ptr->data);
    }
}

struct Node * buildNode(int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = newnode;
    return newnode;
}

void insertAtIndex(struct Node ** head_ref, int index, int data){
    if(head_ref == NULL){
        *head_ref = buildNode(data);
        printf("Element %d is inserted at index 0.", data);
        return;
    }

    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    struct Node * ptr = *head_ref;
    newnode->data = data;

    if(index == 0){
        while(ptr->next != *head_ref){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = *head_ref;
        *head_ref = newnode;
        printf("Element %d is inserted at inedx 0.\n", data);
        return;
    }

    int i = 0;
    while(ptr->next != NULL && i< index-1){
        ptr = ptr->next;
        i++;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    printf("Element %d is inserted at inedx %d.\n", data, index);
    
}

void deleteAtIndex(struct Node ** head_ref, int index){
    if(head_ref == NULL){
        printf("List is empty\n");
        return;
    }

    struct Node * tmp = *head_ref;

    if(index == 0){
        while(tmp->next != *head_ref){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        struct Node * del = *head_ref;
        *head_ref = tmp->next;
        printf("Element %d is deleted at inedx 0.\n", del->data);
        free(del);
        return;
    }

    int i = 0;
    while(tmp->next != NULL && i< index-1){
        tmp = tmp->next;
        i++;
    }
    struct Node * del = tmp->next;
    tmp->next = tmp->next->next;
    printf("Element %d is deleted at index %d.", del->data, index);
    free(del);
}


int main(){

    struct Node * head = NULL;
    struct Node * one = buildNode(7);
    head = one;

    insertAtIndex(&head, 0, 17);
    insertAtIndex(&head, 1, 45);
    insertAtIndex(&head, 0, 245);
    insertAtIndex(&head, 0, 345);
    insertAtIndex(&head, 2, 904);
    display(head);
    insertAtIndex(&head, 4, 954);
    insertAtIndex(&head, 1, 604);
    insertAtIndex(&head, 5, 7077);
    display(head);
    deleteAtIndex(&head, 0);
    display(head);
    deleteAtIndex(&head, 1);
    display(head);
    deleteAtIndex(&head, 5);
    display(head);   
    deleteAtIndex(&head, 3);
    display(head);    

    return 0;
}