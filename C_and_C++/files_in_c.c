#include<stdio.h>
#include<string.h>


int main(){

    FILE *pnt;

    pnt = fopen("sample.txt", "r");
    // pnt = fopen("sample2.txt", "w");
    // pnt = fopen("sample.txt", "a");

    int num;
    int num2;

    if (pnt == NULL){
        printf("File does not exist\n");
    }
    else{
        fscanf(pnt, "%d", &num);
        fscanf(pnt, "%d", &num2);
        fclose(pnt);
        printf("Num is %d\n", num);
        printf("Num is %d\n", num2);
    }

    // Wriring to file
    FILE * fp;
    int num3 = 45;
    fp = fopen("sample2.txt", "w");
    fprintf(fp, "The number is %d\n", num3);
    fprintf(fp, "Thanks for using fprintf\n");
    fclose(fp);

    FILE * fpnt;
    fpnt = fopen("sample3.txt", "r");
    // char c = fgetc(fpnt);
    printf("The value of my character is %c\n", fgetc(fpnt));
    printf("The value of my character is %c\n", fgetc(fpnt));
    printf("The value of my character is %c\n", fgetc(fpnt));
    printf("The value of my character is %c\n", fgetc(fpnt));
    printf("The value of my character is %c\n", fgetc(fpnt));
    printf("The value of my character is %c\n", fgetc(fpnt));
    printf("The value of my character is %c\n", fgetc(fpnt));
    fclose(fpnt);

    FILE * f1;

    f1 = fopen("sample4.txt", "w");
    putc('c', f1);
    putc('c', f1);
    putc('c', f1);
    putc('c', f1);
    fclose(f1);


    char c;
    FILE * f2;
    f2 = fopen("sample3.txt", "r");
    c = fgetc(f2);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(f2);
    }



    return 0;
}