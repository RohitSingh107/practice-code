#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node * next;
};

void display_ll(struct Node * ptr){
    if(ptr == NULL){
        printf("\nList is empty\n");
    }
    else{

        printf("|");
        int i = 0;
        while(ptr->next != NULL){
            printf(" %d ",ptr->data);
            ptr = ptr->next;
            i++;
        }
        printf(" %d |\n", ptr->data);
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
        return *head_ref;
    }
}



struct Node * inserAtIndex(struct Node ** head_ref, int data, int index){
    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));

    if(index == 0){
        insertAtFirst(head_ref, data);
    }
    else{

        if(new_node == NULL){
            printf("Memory is not allocated\n");
            return NULL;
        }
        else{
            struct Node * tmp = *head_ref;
            int i = 0;
            while(i != index - 1){
                tmp = tmp->next;
                i++;
            }
            new_node->data = data;
            new_node->next = tmp->next;
            tmp->next = new_node;

            return *head_ref;
        }
    }
}


void deleteAtIndex(struct Node ** head_ref, int index){
    
    struct Node * tmp = *head_ref;
  
    if(index == 0){
        *head_ref = (*head_ref)->next;
        free(tmp); 
    }
    else{
        struct Node * tmp2 = (*head_ref)->next;
        int i = 0;
        while(i != index - 1){
            tmp = tmp->next;
            tmp2 = tmp2->next;
            i++;
        }
        tmp->next = tmp2->next;
        free(tmp2);
    }
}

struct Node * reverseList(struct Node ** head_ref){

    if(*head_ref == NULL){
        printf("List is empty!\n");
    }
    else{

        struct Node * next = (*head_ref)->next; 
        struct Node * prev = NULL;
        struct Node * current = *head_ref;

        while(next != NULL){
            current->next = prev;
            prev = current;
            current = next;
            next = next->next;
        }
        current->next = prev;
        
        *head_ref = current;

        return *head_ref;
    }
}



int main(){
    // Empty Linked List
    struct Node * head = NULL;

    int c;
    c = 0;
    while(c != 6){

        printf("===========================\n");
        printf("Select the operation to perform: \n 1. Display\n 2. Insert at First\n 3. Insert at Index\n 4. Delete at Index\n 5. Reverse the list\n 6. Exit\n");
        scanf("%d", &c);

        switch (c){

            case 1:

                display_ll(head);
                break;

            case 2:

                printf("-------------------------\n");
                printf("Enter the element to add at first\n");
                int data1;
                scanf("%d", &data1);
                insertAtFirst(&head, data1);

                printf("\n New List:\n");
                display_ll(head);

                break;
            
            case 3:

                printf("-------------------------\n");
                printf("Enter the Index: ");
                int index1;
                scanf("%d", &index1);

                printf("Enter the element to add: ");
                int data2;
                scanf("%d", &data2);
                inserAtIndex(&head, data2, index1);
                printf("\n New List:\n");
                display_ll(head);
                break;


            case 4:

                printf("Enter the Index: ");
                int index2;
                scanf("%d", &index2);
                deleteAtIndex(&head, index2);

                printf("\n New List:\n");
                display_ll(head);
                
                break;
            
            case 5:
                reverseList(&head);
                printf("\n New List:\n");
                display_ll(head);
                break;

            case 6:
                c = 6;
                break;

            default:
                printf("Please Enter the valid choice: \n");
                break;
        }
    }
    return 0;
}