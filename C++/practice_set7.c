#include <stdio.h>

void mult_table(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int a[10];

    for(int i = 0; i< 10; i++){
        a[i] = (i+1) * n;
    }
    
    for(int i = 0; i< 10; i++){
        printf("Value at index: %d is %d\n", i, a[i]);
    }
}

void reversed(int a[], int n){
    int b[n];
    for(int i =0; i<n; i++){
        b[n-1-i] = a[i];
    }

    a = b;

    for(int i =0; i<n; i++){
        printf("%d\n", a[i]);
    }
    
}

void three_mult_table(){
    int x, y, z;

    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);
    printf("Enter the third number: ");
    scanf("%d", &z);

    int table[10][3];
    for(int i =0; i< 10; i++){
        table[i][0] = x*(1+i);
        table[i][1] = y*(1+i);
        table[i][2] = z*(1+i);
       
    }
    for(int i=0; i<10; i++){
        printf("%d   %d   %d\n", table[i][0], table[i][1], table[i][2]);
    }

}

void threeDarray(){
    int x, y, z;
    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);
    printf("Enter the third number: ");
    scanf("%d", &z);
    int arr[x][y][z];
    for (int i = 0; i < x; i++){
        for(int j = 0; j< y; j++){
            for (int k = 0; k< z; k++){
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    for (int i = 0; i < x; i++){
        for(int j = 0; j< y; j++){
            for (int k = 0; k< z; k++){
                printf("element at %d,%d,%d is %d\n",i,j,k, arr[i][j][k]);
                printf("address is %u\n", &arr[i][j][k]);
            }
        }
    }

}


int main(){

    // int n;
    // printf("Enter size of array: ");
    // scanf("%d", &n);

    // int a[n];

    // for(int i = 0; i< n; i++){
    //     printf("Enter value at index %d :", i);
    //     scanf("%d", &a[i]);
    // }
    
    // for(int i = 0; i< n; i++){
    //     printf("Value at index: %d is %d\n", i, a[i]);
    // }

    // printf("Value using pointer at third position: %d\n", *(a + 2));

    // mult_table();



    // int n;
    // printf("Enter size of array: ");
    // scanf("%d", &n);

    // int arr[n];
    // for(int i = 0; i< n; i++){
    //     printf("Enter value at index %d :", i);
    //     scanf("%d", &arr[i]);
    // }

    // reversed(arr, n);

    // three_mult_table();
    threeDarray();

    return 0;
}