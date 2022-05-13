#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    // printf("Size of int on my system is %d\n", sizeof(int));
    // printf("Size of float on my system is %d\n", sizeof(float));
    // printf("Size of char on my system is %d\n", sizeof(char));

    // ptr = (int *) malloc(6 * sizeof(int));

    // for(int i = 0; i<6; i++){
    //     printf("Enter the value ad index %d\n", i);
    //     scanf("%d", &ptr[i]);
    // }

    // for(int i = 0; i<6; i++){
    //     printf("value ad index %d is: %d\n", i, ptr[i]);
    // }
    // printf("Value of ptr is %u\n", ptr);


    int * p2;
    p2 = (int *) calloc(6 , sizeof(int));

    // for(int i = 0; i<6; i++){
    //     printf("Enter the value ad index %d\n", i);
    //     scanf("%d", &ptr[i]);
    // }

    for(int i = 0; i<6; i++){
        printf("value ad index %d is: %d\n", i, p2[i]);
    }
    
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    // int arr[n];
    int * p3 = (int *) malloc(n* sizeof(int));

    for(int i = 0; i<n; i++){
        printf("Enter the value ad index %d\n", i);
        scanf("%d", &p3[i]);
    }

    for(int i = 0; i<n; i++){
        printf("value ad index %d is: %d\n", i, p3[i]);
    }

    int n2;
    printf("Enter the new size: ");
    scanf("%d", &n2);

    p3 = realloc(p3, n * sizeof(int));

    free(p2);
    free(p3);

    for(int i = 0; i<n2; i++){
        printf("Enter the value ad index %d\n", i);
        scanf("%d", &p3[i]);
    }

    for(int i = 0; i<n2; i++){
        printf("value ad index %d is: %d\n", i, p3[i]);
    }

    return 0;
}