#include <stdio.h>
#include <stdlib.h>


struct Node{

    int data;
    struct Node * next;

};



void display_ll(struct Node * ptr){
    // struct Node * temp = (s)
    int i = 0;
    while(ptr->next != NULL){
        printf("Element at %d is %d\n",i, ptr->data);
        ptr = ptr->next;
        i++;
    }
    printf("Element at %d is %d\n",i, ptr->data);
}

struct Node * insertAtFirst(struct Node * head, int data){

    struct Node * ptr = (struct Node * ) malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = data;
    // head_ref = new_node;
    head = ptr;
    // display_ll(head);

    return head;

}

// // void continous_prog(struct Node * head_ref){
// //     int c;
// //     c = 0;

// //     while(c != 4){

// //         printf("===========================\n");
// //         printf("Select the operation to perform: \n 1. Display\n 2. Insert\n 3. Delete\n 4. Exit\n");
// //         scanf("%d", &c);

// //         switch (c){
// //             case 1:
// //                 printf("-------------------------\n");
// //                 display_ll(*head_ref);
// //                 break;
// //             case 2:
// //                 printf("-------------------------\n");
// //                 printf("Enter the element to add at first\n");
// //                 int data;
// //                 scanf("%d", &data);
// //                 insertAtFirst(*head_ref, data);
// //                 break;
// //             case 3:
// //                 printf("-------------------------\n");
// //                 // delete_que();
// //                 break;
// //             case 4:
// //                 c = 4;
// //                 // break;
// //             default:
// //                 printf("Please Enter the valid choice: \n");
// //                 break;
// //         }
// //     }
// // }

int main(){
//     // Empty Linked List
//     struct Node * head = NULL;

    struct Node * head;
    head = (struct Node *) malloc(sizeof(struct Node));
    
    struct Node * n2;
    n2 = (struct Node *) malloc(sizeof(struct Node));

    struct Node * n3;
    n3 = (struct Node *) malloc(sizeof(struct Node));

//     head = n1;

    head->data = 75;
    head->next = n2;

    n2->data = 12;
    n2->next = n3;

    n3->data = 11126;
    n3->next = NULL;



//     // printf("Address is %u\n", n1 );
//     // printf("Address is %u\n",(*n1).next );
//     // printf("size of node is %d\n",sizeof(struct Node));
   
//     // printf("Address is %d\n",(*head).data );
//     // display_ll(head);

//     printf("Address is %d\n",(*head).data );
//     printf("Address is %d\n",(*n1).data );

//     printf("Address is %d\n",(*head).data );
    // display_ll(head);
    insertAtFirst(head, 7);
    
    // display_ll(head);

// //    continous_prog(&head);


    return 0;
}