#include<stdio.h>

int binarySearch(int * a, int size, int element){
    int l = 0;
    int r = size - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == element){
            return m;
        }
        else if(element < a[m]){
            r = m - 1;
        }
        else{
            l = m + 1;
        }

    }
    return -1;
}


int main(){

    // Taking inputs for array
    int n;
    printf("Note: Array should be SORTED\n");
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

    int resLS = binarySearch(arr, size, x);
    if(resLS >= 0){
        printf("Element found at index %d\n", resLS);
    }
    else{
        printf("Element not found\n");
    }


    return 0;
}