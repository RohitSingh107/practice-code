#include<stdio.h>

void multiplication_table(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    for(int i=1; i <= 10; i++){
        printf("%d x %d = %d\n", n, i, n*i);
    }
}

void reverse_mt(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    for(int i=10; i >= 1; i--){
        printf("%d x %d = %d\n", n, i, n*i);
    }
}

void while_natural(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    int i = 1;
    while(i <= n){
        printf("%d,",  i);
        i++;
    }
}

void sum_natural(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    int sum = 0;
    int i = 1;
    while(i <= n){
        sum = sum + i;
        i++;
    }
    printf("%d\n", sum);
}

void do_while_sum_natural(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    int sum = 0;
    int i = 1;
    do{
        sum += i;
        i++;
    }while(i<=n);

    printf("%d\n", sum);
}

void sum_mult(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= 10; i++){
        sum += n*i;
    }
    printf("Sum of multiplication table of %d is %d\n", n, sum);
}

void factorial(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    int fact = 1;
    for(int i = 1; i<= n; i++){
        fact = fact * i;
    }
    printf("Factorial of %d is %d\n", n, fact);
}

void while_factorial(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    int fact = 1;

    int i = 1;
    while(i<=n){
        fact = fact * i;
        i++;
    }

    printf("Factorial of %d is %d\n", n, fact);
}

void prime(){
    printf("Enter the number: ");
    int n;
    scanf("%d", &n);
    int prime = 1;
    int i = 2;
    while(i < n){
        if(n % i == 0){
            prime = 0;
            break;
        }
        i++;
    }
    if(prime){
        printf("This is a prime.\n");
    }
    else{
        printf("This is not prime.\n");
    }
}



int main(){

    // multiplication_table();
    // reverse_mt();
    // while_natural();
    // sum_natural();
    // do_while_sum_natural();
    // sum_mult();
    // factorial();
    // while_factorial();
    prime();


    return 0;
}