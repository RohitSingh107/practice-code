#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};

void listTraversal(struct Node * head){
    struct Node * ptr = head;
    printf("List: ");
    do{
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != NULL);
    printf("\n");
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



struct Node * delMax(struct Node * head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    struct Node * tmp = head->next;
    struct Node * max_node = head;

    while(tmp->next != NULL){
            if(tmp->data > tmp->prev->data){
                max_node = tmp;
            }
            tmp = tmp->next;
        }
    if(max_node == head){
        head->next->prev = NULL;
        head = head->next;
        free(max_node);
        return head;
    }
    else{
        max_node->prev->next = max_node->next;
        max_node->next->prev = max_node->prev;
        printf("Maximux is %d and hence deleted\n", max_node->data);
        free(max_node);
        return head;
    }
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

    insertFirst(&head, 88);
    insertEnd(&last, 58);
    insertFirst(&head, 7);
    listTraversal(head);
    head = delMax(head);
    listTraversal(head);
    


    return 0;
}