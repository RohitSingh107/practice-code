#include <stdio.h>

void mySum(float *a, float *b){

    printf("Sum is %f\n", *a + *b);

    printf("Average is %f\n", (*a + *b) / 2.0);

}

void tenTimes(float * a){
    *a = 10 * (*a);
}


int main(){

    char c = 'R';

    char *pc = &c;
    char **ppc = &pc;
    printf("1 Value of  %c \n", **ppc);
    printf("1 Value of  %c \n", *(&c));
    
    printf("\n2 Value of  %u \n", *ppc);
    printf("3 Value of  %u \n", &c);
    printf("4 Value of  %u \n\n", pc);

    printf("5 Value of  %u \n", ppc);
    printf("6 Value of  %u \n\n", &pc);

    printf("7 Value of  %u \n\n", &ppc);

    float a = 7;
    float b = 10;
    mySum(&a, &b);

    tenTimes(&a);
    printf("%f", a);


    return 0;
}