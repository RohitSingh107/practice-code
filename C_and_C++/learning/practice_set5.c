#include<stdio.h>

void print_pattern(int n){
    // int n;
    // printf("Enter the number: ");
    // scanf("%d", &n);
    int k = (1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            printf("*");
        }
        printf("\n");
        k++;
        k++;
    }
}

int sum_natural(int n){
    if(n <= 0){
        return 0;
    }

    return n + sum_natural(n-1);
}

int fib(int n){
    if(n <= 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(){
    
    print_pattern(3);

    // printf("Sum is %d\n", sum_natural(100));

    // int a = 10;

    // printf("%d %d %d \n", a, ++a, ++a);

    // printf("%d %d %d \n", a , ++a, a++);

    printf("Fibonacci no at this position is: %d \n", fib(100));

    return 0;
}