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

    return x;
}

int main(){

    struct Queue * queue = builQueue(50);


    int c = 0;
    while(c != 4){

        printf("===========================\n");
        printf("Select the operation to perform: \n 1. Display Queue\n 2. Enque\n 3. Dequeue\n 4. Exit\n");
        scanf("%d", &c);

        switch (c){

            case 1:
                display_queue(queue);
                break;

            case 2:
                printf("Enter the element to Enque: ");
                int data1;
                scanf("%d", &data1);
                enqueue(queue, data1);
                printf("New ");
                display_queue(queue);

                break;
            
            case 3:
                printf("%d is Dequeued\n", dequeue(queue));
                printf("New ");
                display_queue(queue);
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