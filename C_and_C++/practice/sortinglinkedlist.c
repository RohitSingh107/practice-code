#include <stdio.h>
#include <stdlib.h>


struct Node{

    int data;
    struct Node * next;

};

void display_ll(struct Node * ptr){
    if(ptr == NULL){
        printf("List is empty\n");
    }
    else{

        printf("List: ");
        int i = 0;
        while(ptr->next != NULL){
            printf(" %d ", ptr->data);
            ptr = ptr->next;
            i++;
        }
        printf(" %d \n", ptr->data);
    }

}

struct Node * insertAtFirst(struct Node ** head_ref, int data){

    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));

    if(new_node == NULL){
        printf("Sorry memory is not allocated");
        return NULL;
    }
    else{

        new_node->data = data;
        new_node->next = *head_ref;
        *head_ref = new_node;
        // printf("Element %d Inserted Sucessfully\n", data);
        return *head_ref;
    }
}



struct Node * insertAtEnd(struct Node * head, int data){

    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));

    if(new_node == NULL){
        printf("Sorry memory is not allocated\n");
        return NULL;
    }
    else{
        struct Node * tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        new_node->data = data;
        new_node->next = NULL;
        tmp->next = new_node;
        printf("Element %d Appended Sucessfully\n", data);
        return head;
    }
}

struct Node * inserAtIndex(struct Node *head, int data, int index){
    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));

    if(new_node == NULL){
        printf("Memory is not allocated\n");
        return NULL;
    }
    else{
        struct Node * tmp = head;
        int i = 0;
        while(i != index - 1){
            tmp = tmp->next;
            i++;
        }
        new_node->data = data;
        new_node->next = tmp->next;
        tmp->next = new_node;

        return head;
    }
}

void insertAfterNode(struct Node * prev_node, int data){
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node; 
}

struct Node * insertAfterValue(struct Node * head, int value, int data){

    struct Node * tmp = head;
    while(tmp->data != value){
        tmp = tmp->next;
    }

    insertAfterNode(tmp, data);
    return head;

}

struct Node * popFromLeft(struct Node ** head_ref){

    struct Node * tmp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(tmp); 
    return *head_ref;
}

void popFromRight(struct Node * head){
    
    struct Node * tmp = head;
    struct Node * tmp2 = head->next;
    while(tmp2->next != NULL){
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    tmp->next = NULL;
    free(tmp2);
}
void deleteTheValue(struct Node * head, int value){
    
    struct Node * tmp = head;
    struct Node * tmp2 = head->next;
    while(tmp2->data != value && tmp2->next != NULL){
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    if(tmp2->data == value){
        tmp->next = tmp2->next;
        free(tmp2);
    }
    else{
        printf("Value doesn't exist in list\n");
    }
}

void deleteAtIndex(struct Node * head, int index){
    
    struct Node * tmp = head;
    struct Node * tmp2 = head->next;
    int i = 0;
    while(i != index - 1){
        tmp = tmp->next;
        tmp2 = tmp2->next;
        i++;
    }
    tmp->next = tmp2->next;
    free(tmp2);
}

struct Node * sort(struct Node * head){
    struct Node * prev = head;
    struct Node * curr = head->next;
    while(prev->next != NULL){
        while(curr != NULL){
            if(prev->data > curr->data){
                int tmp = curr->data;
                curr->data = prev->data;
                prev->data = tmp;
            }
            curr = curr->next;
        }
        prev = prev->next;
        curr = prev->next;
    }
    return head;
}

int main(){
    // Empty Linked List
    struct Node * head = NULL;

    struct Node * n1;
    n1 = (struct Node *) malloc(sizeof(struct Node));
    
    struct Node * n2;
    n2 = (struct Node *) malloc(sizeof(struct Node));

    struct Node * n3;
    n3 = (struct Node *) malloc(sizeof(struct Node));

    head = n1;

    n1->data = 75;
    n1->next = n2;

    n2->data = 12;
    n2->next = n3;

    n3->data = 26;
    n3->next = NULL;


   



    insertAtFirst(&head, 71);
    insertAtFirst(&head, 72);
    insertAtFirst(&head, 45);
    insertAtFirst(&head, 72);
    insertAtFirst(&head, 9);
    insertAtFirst(&head, 27);
    display_ll(head);
    
    struct Node * sorted = sort(head);
    display_ll(sorted);


    return 0;
}