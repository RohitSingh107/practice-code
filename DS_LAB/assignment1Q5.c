#include<stdio.h>
#include<stdlib.h>


struct Node{
    char data;
    struct Node * next;
};

void push(struct Node ** top, char data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}

char pop(struct Node ** top){
    if(*top == NULL){
        printf("Stack is Underflowed!\n");
    }
    else{
        struct Node * tmp = *top;
        int x = tmp->data;

        *top = (*top)->next;
        free(tmp);
        return x;
    }
}

void operations(struct Node ** top, char * s){
    
    printf("Applying all this operations:\n");
    printf("%s\n\n\n", s);

    printf("Sequence of values returned by pop operation.\n");
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' '){}
 
        else if(s[i] == '*'){
            printf("%c ", pop(top));
        }
        else{
            push(top, s[i]);
        }
        i++;
    }

}


int main(){

    // Initial Empty LIFO Stack
    struct Node * top = NULL; 

    char sequence[] = "E A S * Y * Q U E * * * S T * * * I O * N * * *";

    operations(&top, sequence);
    
    return 0;
}