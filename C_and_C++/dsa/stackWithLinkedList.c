#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void display_stack(struct Node * top){
    if(top == NULL){
        printf("Stack is underflowed!\n");
    }
    else{
        printf("Stack:\n");
        struct Node * tmp = top;
        while(tmp != NULL){
            printf("|\t%d\t|\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

void push(struct Node ** top, int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
    printf("Element %d is pushed.\n", data);
}

int pop(struct Node ** top){
    if(*top == NULL){
        printf("Stack is already empty\n");
        return -1;
    }
    else{
        struct Node * tmp = *top;
        int x = tmp->data;

        *top = (*top)->next;
        printf("Element %d is popped\n", x);
        free(tmp);
        return x;
    }
}



int main(){

    struct Node * top = NULL;

    display_stack(top);
    push(&top, 9);
    push(&top, 7);
    push(&top, 8);
    push(&top, 10);
    display_stack(top);
    pop(&top);
    pop(&top);
    display_stack(top);
    push(&top, 310);
    push(&top, 1910);
    push(&top, 110);
    display_stack(top);


    return 0;
}