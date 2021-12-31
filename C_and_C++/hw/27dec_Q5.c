#include <stdio.h>

int main(){

    int n;
    printf("Enter the size of farray: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i< n; i++){
        printf("Enter the element at index %d in array: ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for(int i = 1; i< n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("Maximux number is %d", max);

    return 0;
}