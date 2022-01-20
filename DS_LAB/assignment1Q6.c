#include<stdio.h>

#define N 100
char stack[N];
int top = -1;

int stack_in(){
    if(top >= N - 1){
        printf("Stack is full!\n");
        return -1;
    }
    else{
        top++;
        printf("Enter the character at index %d >: ", top);
        char e;
        scanf(" %c", &e);

        stack[top] = e;
        return 0;
    }
}

int stack_out(){
    if(top <= -1){
        printf("Stack is underflowed!\n");
        return -1;
    }
    else{
        printf("%c", stack[top]);
        top--;
        return 0;
    }
}


int main(){

    int len;
    printf("Enter the No. of characters you want to add: ");
    scanf("%d", &len);

    char text[len];
    printf("Enter the characters one by one in sequence\n\n");
    for(int i = 0; i <len; i++){
        stack_in();
    }

    printf("\nReverse of characters using stack:\n");
    for(int i = 0; i <len; i++){
        stack_out();
    }

    return 0;
}

