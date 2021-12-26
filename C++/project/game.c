#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int num, guess, count = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    // printf("The number is %d\n", num);

    do{
        printf("Enter the number: ");
        scanf("%d", &guess);
        count++;
        if(guess > num){
            printf("Lower number please.\n");
        }
        else if(guess<num){
            printf("Higher number please.\n");
        }
        else{
            printf("Bingo!\n");
            printf("You guessed in %d try\n", count);
        }
    }while(guess != num);

    return 0;
}