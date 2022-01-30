#include<stdio.h>
#include<stdlib.h>
// #include<string.h>


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

    struct Stack * stack = buildStack(5);

    push(stack, 6);
    push(stack, 5);
    push(stack, 100);
    display_stack(stack);
    pop(stack);
    display_stack(stack);

    


    return 0;
}
