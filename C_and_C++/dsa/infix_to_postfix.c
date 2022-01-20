#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node * next;
};

void display_stack(struct Node * top){
    if(top == NULL){
        printf("Stack is underflowed!\n");
    }
    else{
        printf("Here is your stack:\n");
        struct Node * tmp = top;
        while(tmp != NULL){
            printf("|\t%c\t|\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

void push(struct Node ** top, char data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}

char pop(struct Node ** top){
    if(*top == NULL){
        printf("Stack is already empty\n");
        return ' ';
    }
    else{
        struct Node * tmp = *top;
        char x = tmp->data;

        *top = (*top)->next;
        free(tmp);
        return x;
    }
}

// int isEmpty();

char * infixToPostfix(char * infix){
    printf("%s", infix + 1);
    // struct Node * top_postfix = NULL;
    // int i = 0;
    // while(infix[i] != '\0'){
    //     if(!isOperator(infix[i])){
    //         push(&top_postfix, infix[i]);
    //         i++;
    //     }
    //     else{

    //     }
    // }

}



int main(){

    struct Node * top_infix = NULL;

    char * infix = "a-b+t/6";
    // printf("%s", infix);
    infixToPostfix(infix);

    return 0;
}