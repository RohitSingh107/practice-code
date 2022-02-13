#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Queue{
    struct Node * front, * rear;
};

void display(struct Queue * Q){
    printf("\nQueue is: \n");
    struct Node * tmp = Q->front;
    while(tmp != NULL){
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
}

struct Node * buildNode(int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
}

struct Queue * buildQueue(){
    struct Queue * newQueue = (struct Queue *) malloc(sizeof(struct Queue)); 
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

void enQueue(struct Queue * Q, int data){

    struct Node * n = buildNode(data);
    
    if (Q->rear == NULL){
        Q->front = Q->rear = n;
        printf(" %d is Enqueued.\n", data);
        return;
    }

    Q->rear->next = n;
    Q->rear = n;
    printf(" %d is Enqueued.\n", data);
}

void deQueue(struct Queue * Q){

    if(Q->front == NULL){
        printf("Que is Empty\n");
        return;
    }

    struct Node * tmp = Q->front;
    Q->front = Q->front->next;

    if (Q->front == NULL){
        Q->rear = NULL;
    }
    printf("%d is dequeued\n", tmp->data);
    free(tmp);
}

int main(){

    // New Queue
    struct Queue * Q = buildQueue();

    enQueue(Q, 7);
    enQueue(Q, 174);
    display(Q);
    enQueue(Q, 47);
    enQueue(Q, 847);
    display(Q);
    deQueue(Q);
    display(Q);
    deQueue(Q);
    display(Q);

    return 0;
}