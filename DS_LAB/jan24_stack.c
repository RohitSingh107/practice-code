#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int capacity;
    int size;
    int * array;
};

struct Stack * buildStack(int cap){
    struct Stack * newStack = (struct Stack *) malloc(sizeof(struct Stack));
    newStack->capacity = cap;
    newStack->top = -1;
    newStack->size = 0;
    newStack->array = (int *) malloc(cap * sizeof(int));
    return newStack;
}

int isFull(struct Stack * st){
    return (st->top == st->capacity -1);
}

int isEmpty(struct Stack * st){
    return (st->top == -1);
}

void display_stack(struct Stack * st){

    if(isEmpty(st)){
        printf("Stack is Empty!\n");
        return;
    }

    printf("\nStack is:\n");
    for(int i = st->size -1; i >= 0; i--){
        printf("|\t%d\t|\n", st->array[i]);
    }
}

void push(struct Stack * st, int data){
    
    if(isFull(st)){
        printf("Stack is overfowed\n");
        return;
    }

    st->array[++st->top] = data;
    st->size++;

    printf("Element %d is pushed to stack.\n", st->array[st->top]);
}

int pop(struct Stack * st){
    st->size--;
    return st->array[st->top--];
}

int main(){

    // Empty Stack
    struct Stack * stack = buildStack(100);
    int c = 0;
    while(c != 4){

        printf("===========================\n");
        printf("Select the operation to perform: \n 1. Display Stack\n 2. Push\n 3. Pop\n 4. Exit\n");
        scanf("%d", &c);

        switch (c){

            case 1:
                display_stack(stack);
                break;

            case 2:
                printf("Enter the element to Push: ");
                int data1;
                scanf("%d", &data1);
                push(stack, data1);
                break;
            
            case 3:
                printf("%d is Popped\n", pop(stack));
                break;

        
            case 4:
                c = 4;
                break;

            default:
                printf("Please Enter the valid choice: \n");
                break;
        }
    }
    return 0;
}
