//Doubly link list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
}; struct node*head = NULL;

void createnode_beg(){
    int info;
    printf("Enter the data for list: ");
    scanf("%d",&info);
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->next = head;
    temp->prev = NULL;
    head= temp;

}

void traverse(){
    printf("traverse ");
    struct node* temp;
    temp = head;
    if(temp==NULL){
    printf("list is empty");
    return;
    }
    else {
        while(temp!=NULL){
            printf(" %d ",temp->data);
            temp = temp->next;
        }
    }
}

void insert(){
    int pos,info,i=1;
    struct node*temp,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter the position to insert and data: ");
    scanf("%d",&pos);
    scanf("%d",&info);
    newnode->data = info;
    temp = head;

    if(pos == 1){
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        return;
    }
    while(i< pos-1){
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    temp->next->prev = newnode;
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete(){
     
}

int main (){
    
    createnode_beg();
    createnode_beg();
    createnode_beg();
    createnode_beg();
    traverse();
    insert();
    traverse();
    delete();
    //reverse();
    int a,b;


    
}