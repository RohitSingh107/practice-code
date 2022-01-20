#include<stdio.h>

int linearSearch(int * a, int size, int element){

    for(int i = 0; i< size; i++){
        if(a[i] == element){
            return i;
        }
    }
    return -1;
}


int main(){

    // Taking inputs for array
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i< n; i++){
        printf("Enter the element at index %d in fisrt array: ", i);
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr)/sizeof(int);

    // Taking element input to search
    int x;
    printf("\nEnter the Element to search: ");
    scanf("%d", &x);

    int resLS = linearSearch(arr, size, x);
    if(resLS >= 0){
        printf("Element found at index %d\n", resLS);
    }
    else{
        printf("Element not found\n");
    }

    return 0;
}