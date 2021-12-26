#include<stdio.h>

void read_integers(){
    FILE * f;
    f = fopen("sample.txt", "r");
    int n1, n2, n3;
    
    fscanf(f, "%d", &n1);
    fscanf(f, "%d", &n2);
    fscanf(f, "%d", &n3);

    printf("Numbers are %d, %d and %d\n", n1, n2, n3);
    fclose(f);
}

void write_table(){
    int n;
    printf("Enter the number to print table: ");
    scanf("%d", &n);

    FILE * f;
    f = fopen("sample5.txt", "a");

    for(int i = 1; i<=10; i++){
        fprintf(f, "%d x %d = %d\n", n, i, n*i);
    }
    fprintf(f, "\n");

    fclose(f);
}

void read_write_twice(){
    FILE * f1;
    FILE * f2;
    f1 = fopen("sample3.txt", "r");
    f2 = fopen("sample2.txt", "a");
    fprintf(f2, "\n");
    char c;
    c = fgetc(f1);
    while(c != EOF){
        fputc(c, f2);
        fputc(c, f2);
        c = fgetc(f1);
    }

    // char d;
    // d = fgetc(f1);
    // while(d != EOF){
    //     fputc(d, f2);
    //     d = fgetc(f1);
    // }
    fclose(f1);
    fclose(f2);
}

int main(){

    // read_integers();

    // write_table();

    read_write_twice();


    return 0;
}