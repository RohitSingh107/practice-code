#include<stdio.h>
// #include<stdlib.h>
// #include<string.h>







int main(){

    int ar[3] = {4,5,3};

    int arr[3][4] = {{4,6,3,5}, {75,36,32, 41}, {12, 31, 22, 78}};

    int * p = ar;

    int (*ptr)[4] = arr;  

    printf("1. ptr is %u, arr is %u\n", ptr , arr);
    printf("2. ptr is %u, arr is %u\n", (ptr+1) , (arr +1)); // arr pointing to first 1d array
    printf("3. ptr is %u, arr is %u\n", (*ptr+1) , (*arr +1));
    printf("4. ptr is %d, arr is %d\n", *(*ptr+1) , *(*arr +1));
    printf("5. ptr is %u, arr is %u\n", *(ptr+1) , *(arr +1));
    printf("6. ptr is %u, arr is %u\n", **(ptr+1) , **(arr +1));
    printf("7. ptr is %d\n", *(*(ptr+2) + 1));
    printf("8. ptr is %u\n", *(arr + 1));
    printf("9. ptr is %u\n", *(arr + 1));

    printf("Your Matrix: \n");
    for(int i = 0; i<3; i++){
        printf("|\t");
        for(int j =0; j<4; j++){
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("|\n");
    }

    // printf();


    


    return 0;
}