#include<stdio.h>
#include<string.h>

int main(){

    char s[] = {'R', 'o', 'h', 'i', 't', '\0'};
    int a[] = {4, 5, 3};

    printf("String is %s\n", s);
    printf("String is %u\n", &s);
    printf("String is %u\n", &s[0]);
    printf("String is %u\n", &s[1]);
    printf("String is %u\n", &s[2]);
    // printf("Int Array is %d\n", a[2]);

    char r[] = "Rohit";
    printf("String is %s\n", r);

    char b[] = "Singh";
    int i =0;
    do{
        printf("%c", b[i]);
        i++;
    }while(b[i] != '\0');
    printf("\n");

    // printf("\nEnter the string: ");
    // char st[50];
    // // scanf("%s", &st);
    // gets(st);

    // puts(st);
    // printf("Entered String is %s\n", st);

    char * pnr = "Rohit Singh";
    puts(pnr);
    pnr = "Something else";
    puts(pnr);
    
    printf("Entered String is %d\n", strlen(pnr));

    char sr[] = "This is me";
    char tg[30];
    strcpy(tg, sr);
    printf("sr is %s\n", sr);
    printf("tg is %s\n", tg);

    strcat(r, tg);
    puts(r);

    printf("\n Comaparision: %d\n", strcmp("Thisss", "Thiss"));


    printf("pnr is: %s\n", pnr);
    char * p2 = pnr;

    printf("p2 is: %s\n", p2);
    // printf("p2 is: %s\n", *p2);
    printf("address of pnr is: %u\n", &pnr);
    printf("address of pnr is: %u\n", &pnr);
    printf("p2 (u) is: %u\n", p2);
    printf("p2 (same as above) is: %u\n", p2);
    printf("p2 is (Ascii value): %u\n", *p2);
    printf("p2 is (Ascii value): %d\n", *p2);
   



    return 0;
}