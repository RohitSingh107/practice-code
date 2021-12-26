#include<stdio.h>
#include<string.h>



struct Vector {
    int x;
    int y;
};

struct Complex {
    int r;
    int i;
};

struct BankAccount {
    char * name;
    float balance;
};

struct MyTime {
    int day;
    char * month;
    int year;
    int hour;
    int minute;
    int second;
};

void time_display(struct MyTime t){
    printf("Time: %d-%s-%d %d:%d:%d", t.year, t.month, t.day, t.hour, t.minute, t.second);
}

void bank_display(struct BankAccount b){
    printf("%s have account balance of %f \n", b.name, b.balance);
}

void vector_display(struct Vector v){
    printf("x cordinates of Vector is : %d\n", v.x);
    printf("y cordinates of Vector is : %d\n", v.y);
}

void complex_display(struct Complex c){
    printf("Real component is : %d\n", c.r);
    printf("Imaginary component is : %d\n", c.i);
}

struct Vector sum_vector(struct Vector a, struct Vector b){
    struct Vector result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

void complex_array(){
    int n;
    printf("Enter the number of complex no to create: ");
    scanf("%d", &n);
    
    struct Complex c[n];

    for(int j=0; j<n; j++){
        printf("------------------------\n");
        printf("Enter the Real components of Complex no %d: ", j+1);
        scanf("%d", &c[j].r);

        printf("Enter the Imaginary components of Complex no %d: ", j+1);
        scanf("%d", &c[j].i);
    }
    for(int j =0; j<n; j++){
        printf("--------------------\n");
        printf("Component of no: %d\n", j+1);
        complex_display(c[j]);
    }
}

int main(){

    struct Vector v1, v2;

    v1.x = 4;
    v1.y = 9;

    v2.x = 7;
    v2.y = 489;

    struct Vector v3 = sum_vector(v1, v2);

    vector_display(v1);
    vector_display(v2);
    vector_display(v3);

    struct Complex c1;
    c1.r = 5;
    c1.i = 57;

    complex_display(c1);

    // complex_array();

    struct BankAccount b1;
    b1.name = "Rohit";
    b1.balance = 450;

    bank_display(b1);

    struct MyTime t1;
    t1.year = 2021;
    t1.month = "Dec";
    t1.day = 24;
    t1.hour = 9;
    t1.minute = 39;
    t1.second = 1;

    time_display(t1);

    return 0;
}