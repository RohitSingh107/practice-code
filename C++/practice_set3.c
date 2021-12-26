#include<stdio.h>

int main(){

    int a = 10;
    if (a==11){
        printf("I am 11");
    }
    else{
        printf("I am not 11\n");
    }
    // Question 2

    // int sub1;
    // int sub2;
    // int sub3;
    // int total;

    // printf("Enter the percentage marks of sub1\n");
    // scanf("%d", &sub1);

    // printf("Enter the percentage marks of sub2\n");
    // scanf("%d", &sub2);
    
    // printf("Enter the percentage marks of sub3\n");
    // scanf("%d", &sub3);

    // printf("Enter the total percentage marks\n");
    // scanf("%d", &total);

    // if((total >= 40) &&  (sub1 >= 33 && sub2 >= 33 && sub3 >= 33)){
    //     printf("Student is passed\n");
    // }
    // else{
    //     printf("Student is failed\n");
    // }


    // Question 3

    // printf("Enter your Income in lacs: ");
    // float inc;
    // scanf("%f", &inc);
    // if(inc >= 10){
    //     printf("You have to pay %f as tax\n", inc * 0.3);
    // }
    // else if(inc >= 5){
    //     printf("You have to pay %f as tax\n", inc * 0.2);
    // }
    // else if(inc >= 2.5){
    //     printf("You have to pay %f as tax\n", inc * 0.05);
    // }
    // else{
    //     printf("You don't have to pay taxes");
    // }

    // printf("Enter the yeat to check: ");
    // int year;
    // scanf("%d", &year);
    // if((year % 4 == 0) && ((year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))){
    //     printf("This is a Leap year\n");
    // }
    // else{
    //     printf("This is not a leap year\n");
    // }

    // Question 5
    // printf("Enter the char: ");
    // char ch;
    // scanf("%c", &ch);
    // if(ch>=97 && ch<=122){
    //     printf("This is a char\n");   
    // }
    // else{
    //     printf("This is not a char\n");
    // }

    // Question 6
    int i1;
    int i2;
    int i3;
    int i4;
    printf("Enter First No.\n");
    scanf("%d", &i1);
    
    printf("Enter Second No.\n");
    scanf("%d", &i2);

    printf("Enter Third No.\n");
    scanf("%d", &i3);

    printf("Enter Fourth No.\n");
    scanf("%d", &i4);

    int grt = i1;

    if(i2 > grt){
        grt = i2;
    }
    if(i3 > grt){
        grt = i3;
    }
    if(i4 > grt){
        grt = i4;
    }
    printf("%d", grt);

    return 0;
}
