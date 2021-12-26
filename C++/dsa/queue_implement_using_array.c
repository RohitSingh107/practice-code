#include <stdio.h>

#define N 4

int f = -1;
int r = -1;
int queue[N];

void queue_display(){

    if(f == -1 && r == -1){
        printf("Queue is Empty!\n");
    }
    else{
        for(int i = f; i <= r; i++){
            printf("Element at index %d is : %d\n", i, queue[i]);
        }
    }
}

int insert_que(){
    
    if(r == N-1){
        printf("Queue is full!\n");
        return -1;
    }
    else if(f == -1 && r == -1){
        f = 0;
        r = 0;
        int val;
        printf("Enter the element to insert: ");
        scanf("%d", &val);
        queue[r] = val;
        printf("Element %d is sucessfully is inserted.\n", val);
        return 0;

    }
    else{
        int val;
        printf("Enter the element to insert: ");
        scanf("%d", &val);
        r++;
        queue[r] = val;
        printf("Element %d is sucessfully is inserted.\n", val);
        return 0;
    }
}

int delete_que(){
    if(r == -1 && f == -1){
        printf("Que is underflowed!\n");
        return 0;
    }
    else if(r == f){
        int v = queue[r];
        f = -1;
        r = -1;
        return v;
    }
    else{
        f++;
    }
}

int main(){

    int c;
    c = 0;

    while(c != 4){

        printf("===========================\n");
        printf("Select the operation to perform: \n 1. Display\n 2. Insert\n 3. Delete\n 4. Exit\n");
        scanf("%d", &c);

        switch (c){
            case 1:
                queue_display();
                break;
            case 2:
                insert_que();
                break;
            case 3:
                delete_que();
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