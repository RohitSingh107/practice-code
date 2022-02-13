#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

void display(struct Node * head){

     struct Node *tmp = head;

    printf("\nTraversal in forward direction\n");
    while(tmp->next != NULL){
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
    printf(" %d \n", tmp->data);

    printf("Traversal in backward direction\n");
    while(tmp->prev != NULL){
        printf(" %d ", tmp->data);
        tmp = tmp->prev;
    }
    printf(" %d \n", tmp->data);
}

struct Node * buildNode(int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertAtIndex(struct Node ** head_ref, int index, int data){
    if(*head_ref == NULL){
        *head_ref = buildNode(data);
        printf("Inserted Element %d at index %d \n", data, index);
        return;
    }
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    if(index == 0){
        newnode->prev = NULL;
        newnode->next = *head_ref;
        (*head_ref)->prev = newnode;
        *head_ref = newnode;
        printf("Inserted Element %d at index %d \n", data, index);
        return;
    }

    struct Node * tmp = *head_ref;
    int i = 0;
    while(tmp->next != NULL && i < index-1){
        tmp = tmp->next;
        i++;
    }
    newnode->prev = tmp;
    tmp->next->prev = newnode;
    newnode->next = tmp->next;
    tmp->next = newnode;
    printf("\nInserted Element %d at index %d \n", data, index);
}

void deleteAtIndex(struct Node ** head_ref, int index){
    struct Node * tmp = *head_ref;

    if(index == 0){
        (*head_ref)->next->prev = NULL;
        *head_ref = (*head_ref)->next;
        int x = tmp->data;
        printf("\nElement %d deleted at index %d \n", x, index);
        free(tmp);
        return;
    }

    int i = 0;
    while(tmp->next != NULL && i< index-1){
        tmp = tmp->next;
        i++;
    }
    tmp->next->next->prev = tmp;
    struct Node * del = tmp->next;
    tmp->next = tmp->next->next;
    int x = del->data;
    printf("Element %d deleted at index %d \n", x, index);
    free(del);

}

int main()
{
    struct Node * one = buildNode(7);
    struct Node * head = NULL;
    head = one;

    display(head);
    insertAtIndex(&head, 0, 6);
    insertAtIndex(&head, 0, 64);
    insertAtIndex(&head, 1, 99);
    insertAtIndex(&head, 3, 59);
    insertAtIndex(&head, 2, 79);
    insertAtIndex(&head, 0, 178);
    display(head);

    deleteAtIndex(&head, 0);
    display(head);
    deleteAtIndex(&head, 2);
    display(head);

    return 0;
}
