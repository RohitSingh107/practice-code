#include<stdio.h>

#define N 4
int stack[N];
int top = -1;

void display_stack(){
    if(top <= -1){
        printf("Stack is Empty\n");
    }
    else{
        for(int i = 0; i<=top; i++){
            printf("Element at index %d: %d\n", i, stack[i]);
        }
    }
}

int insert_stack(){
    if(top >= N - 1){
        printf("Stack is full!\n");
        return -1;
    }
    else{
        printf("Enter the element to insert: ");
        int e;
        scanf("%d", &e);
        top++;
        stack[top] = e;
        printf("Element %d is sucessfully inserted.\n", e);
        return 0;
    }
}

int delete_stack(){
    if(top <= -1){
        printf("Stack is underflowed!\n");
        return -1;
    }
    else{
        printf("Element %d is deleted\n", stack[top]);
        top--;
        return 0;
    }
}


int main(){


    // int e;
    int input = 0;

    while(input != 4){
        printf("=================================\n");
        printf("Select the operation to perform:\n 1. Display\n 2. Insert\n 3. Delete\n 4. Exit\n");

        scanf("%d", &input);

        switch (input)
        {
        case 1:
            display_stack();
            break;
        case 2:
            insert_stack();
            break;
        case 3:
            delete_stack();
            break;
        case 4:
            input = 4;
            break;
        
        default:
            printf("Please enter valid operation!\n");
            break;
        }
    }


    return 0;
}

