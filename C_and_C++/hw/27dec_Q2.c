#include <stdio.h>

int main(){

    // Question 2: Take inputs from user and add those numbers.
    int n1, n2;
    
    printf("Enter the fist number: ");
    scanf("%d", &n1);

    printf("Enter the second number: ");
    scanf("%d", &n2);

    printf("Sum of %d and %d is %d: \n", n1, n2, n1 + n2);

    return 0;
}