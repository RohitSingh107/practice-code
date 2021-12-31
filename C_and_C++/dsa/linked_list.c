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

        int i = 0;
        while(ptr->next != NULL){
            printf("Element at %d is %d\n",i, ptr->data);
            ptr = ptr->next;
            i++;
        }
        printf("Element at %d is %d\n",i, ptr->data);
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

void continous_prog(struct Node ** head_ref){
    int c;
    c = 0;

    while(c != 10){

        printf("===========================\n");
        printf("Select the operation to perform: \n 1. Display\n 2. Insert at First\n 3. Insert at Index\n 4. Insert After a element\n 5. Insert at End\n 6. Pop from Feft\n 7. Pop from Right\n 8. Delete the element\n 9. Delete at Index\n 10. Exit\n");
        scanf("%d", &c);

        switch (c){

            case 1:

                printf("-------------------------\n");
                display_ll(*head_ref);
                break;

            case 2:

                printf("-------------------------\n");
                printf("Enter the element to add at first\n");
                int data1;
                scanf("%d", &data1);
                insertAtFirst(head_ref, data1);
                break;
            
            case 3:

                printf("-------------------------\n");
                printf("Enter the Index: ");
                int index1;
                scanf("%d", &index1);

                printf("Enter the element to add: ");
                int data2;
                scanf("%d", &data2);
                inserAtIndex(*head_ref, data2, index1);
                break;

            case 4:

                printf("-------------------------\n");
                printf("Enter the element in list to add after: ");
                int value1;
                scanf("%d", &value1);

                printf("Enter the element to add: ");
                int data3;
                scanf("%d", &data3);
                insertAfterValue(*head_ref, value1, data3);
                break;

            case 5:

                printf("-------------------------\n");
                printf("Enter the element to add at end\n");
                int data4;
                scanf("%d", &data4);
                insertAtEnd(*head_ref, data4);
                break;


            case 6:

                popFromLeft(head_ref);
                break;

            case 7:

                popFromRight(*head_ref);
                break;

            case 8:

                printf("Enter the Value: ");
                int value2;
                scanf("%d", &value2);
                deleteTheValue(*head_ref, value2);
                break;
            
            case 9:

                printf("Enter the Index: ");
                int index2;
                scanf("%d", &index2);
                deleteAtIndex(*head_ref, index2);
                break;

            case 10:
                c = 10;
                // break;

            default:
                printf("Please Enter the valid choice: \n");
                break;
        }
    }
}


int main(){
    // Empty Linked List
    struct Node * head = NULL;

    // struct Node * n1;
    // n1 = (struct Node *) malloc(sizeof(struct Node));
    
    // struct Node * n2;
    // n2 = (struct Node *) malloc(sizeof(struct Node));

    // struct Node * n3;
    // n3 = (struct Node *) malloc(sizeof(struct Node));

    // head = n1;

    // n1->data = 75;
    // n1->next = n2;

    // n2->data = 12;
    // n2->next = n3;

    // n3->data = 26;
    // n3->next = NULL;


    // display_ll(head);
    // insertAfterNode(head, 6);
    // insertAtFirst(&head, 7);
    // insertAtFirst(&head, 45);
    // insertAtFirst(&head, 63);
    // insertAtFirst(&head, 12);
    // insertAtFirst(&head, 3);
    // insertAtFirst(&head, 453);
    // display_ll(head);
    // printf("----------\n");
    // inserAtIndex(head, 56, 2);
    // display_ll(head);
    // inserAtIndex(head, 100, 4);
    // display_ll(head);

    // insertAtEnd(head, 999);
    // display_ll(head);



    // insertAtFirst(&head, 71);
    // insertAtFirst(&head, 72);
    // insertAtFirst(&head, 45);
    // insertAtFirst(&head, 27);
    // display_ll(head);
    // popFromLeft(&head);
    // display_ll(head);
    // deleteAtIndex(head, 2);
    // display_ll(head);
    // insertAfterValue(head, 45, 100);
    // display_ll(head);
    // insertAfterValue(head, 71, 101);
    // display_ll(head);

   continous_prog(&head);


    return 0;
}