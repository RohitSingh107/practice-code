#include <stdio.h>

int main(){

    // Question 3: Take inputs from user to form a array and sum it's elements
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i< n; i++){
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for(int i = 0; i< n; i++){
        sum += arr[i];
    }
    printf("Sum of array is %d", sum);

    

    return 0;
}