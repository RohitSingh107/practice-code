#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
};

void display(struct Node * head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node * tmp = head;
    printf("| ", tmp->data);
    while(tmp->next != NULL){
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
    printf(" %d |\n", tmp->data);
}

void insertAtFirst(struct Node ** head_ref, int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    
    if(*head_ref == NULL){
        newnode->next = NULL;
    }
    else{
      (*head_ref)->prev = newnode;
      newnode->next = *head_ref;
    }
    *head_ref = newnode;  
}

void deleteAtFirst(struct Node ** head_ref){
    if(*head_ref == NULL){
        printf("List is already empty\n");
    }
    else{
        struct Node * tmp = *head_ref;
        if(tmp->next == NULL){
            *head_ref = NULL;
            free(tmp);
            return;
        }
        *head_ref = (*head_ref)->next;
        (tmp->next)->prev = NULL;
        free(tmp);
        return;
    }
}

void insertAtIndex(struct Node ** head_ref, int index, int data){
    
    if(index == 0){
        insertAtFirst(head_ref, data);
        return;
    }
    struct Node * tmp = *head_ref;
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    int i = 0;
    while(tmp != NULL && i < index - 1){
        // printf("Printing i : %d %d\n",i, tmp->data);
        tmp = tmp->next;
        i++;
    }
    newnode->next = tmp->next;
    newnode->prev = tmp;
    tmp->next->prev = newnode;
    tmp->next = newnode;
    // printf("Printing i : %d %d\n",i, tmp->data);
}




int main(void){

    struct Node * head = NULL;
    struct Node * last = NULL;

    insertAtFirst(&head, 4);
    insertAtFirst(&head, 6);
    insertAtFirst(&head, 7);
    insertAtFirst(&head, 9);
    insertAtFirst(&head, 19);

    // printf("Data is %d \n", (head->next->next)->prev->prev->data);

    display(head);
    insertAtIndex(&head, 0, 78);
    deleteAtFirst(&head);
    deleteAtFirst(&head);
    deleteAtFirst(&head);
    deleteAtFirst(&head);
    deleteAtFirst(&head);
    deleteAtFirst(&head);
    display(head);




    return 0;
}