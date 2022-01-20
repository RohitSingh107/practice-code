#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void display_stack(struct Node * top){
    if(top == NULL){
        printf("Stack is underflowed!");
    }
    else{
        printf("Here is your stack:\n");
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
        free(tmp);
        return x;
    }
}

// int isEmpty();



int main(){

    struct Node * top = NULL;

    push(&top, 7);
    push(&top, 8);
    push(&top, 9);
    push(&top, 10);

    // printf("data is %d\n", top->data);
    // printf("data is %d\n", top->next->data);
    // printf("data is %d\n", top->next->next->data);
    // printf("data is %d\n", top->next->next->next->data);
    
    display_stack(top);
    // printf("data is %d\n", top->data);
    pop(&top);
    // printf("data is %d\n", top->data);
    // printf("data is %d\n", top->next->data);
    
    display_stack(top);

    return 0;
}