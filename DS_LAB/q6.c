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
        printf("Element %d Inserted Sucessfully\n", data);
        return *head_ref;
    }
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