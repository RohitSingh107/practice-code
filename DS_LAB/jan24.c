#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size, front, rear;
    int capacity;
    int * array; 
};

struct Queue * builQueue(int cap){

    struct Queue * newQue = (struct Queue *) malloc(sizeof(struct Queue)); 
    
    newQue->capacity = cap;
    newQue->front = newQue->size = 0;
    newQue->rear = cap - 1;
    newQue->array = (int *) malloc(newQue->capacity * sizeof(int));

    return newQue;
}

int isFull(struct Queue * queue){
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue * queue){
    return (queue->size == 0);
}

void display_queue(struct Queue * que){
    if(isEmpty(que)){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Queue:  |  ");
        for(int i = que->front; i <= que->rear; i++){
            printf("%d  ", que->array[i]);
        }
        printf("|\n");
    }

}

void enqueue(struct Queue * que, int data){

    if (isFull(que)){
        printf("Que is full!\n");
        return;
    }

    que->rear = (que->rear + 1) % que->capacity;
    que->array[que->rear] = data;

    que->size++; 
    printf("%d enqued sucessfully!\n");
}

int dequeue(struct Queue * que){
    if(isEmpty(que)){
        printf("Que is empty\n");
        return -1;
    }

    int x = que->array[que->front];
    que->front = (que->front + 1) % que->capacity;
    que->size--;

    printf("%d is dequeued.\n", x);
    return x;
}

int main(){

    struct Queue * queue = builQueue(50);

    display_queue(queue);

    enqueue(queue, 1);
    enqueue(queue, 2);

    display_queue(queue);

    dequeue(queue);

    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("front and rear is %d and %d\n", queue->front, queue->rear);
    printf("size is %d\n", queue->size);
    display_queue(queue);
    enqueue(queue, 6);
    enqueue(queue, 7);
    display_queue(queue);
    printf("front and rear is %d and %d\n", queue->front, queue->rear);
    enqueue(queue, 8);
    enqueue(queue, 9);

    // dequeue(queue);
    display_queue(queue);

    // printf("Element is %d, %d", queue->rear - 1, queue->rear);


    return 0;
    
}