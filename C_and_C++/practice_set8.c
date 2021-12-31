#include <stdio.h>
#include <string.h>

char * check_c(char * pnt, char c){

    for(int i = 0; i < strlen(pnt); i++){
        if(pnt[i] == c){
            return "Yes";
        }
    }
    return "No";
}

int count_c(char s[], char c){
    
    int count = 0;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == c){
            count++;
        }
        i++;
    }

    return count;
}

void myStrCpy(char * x, char * y){
    int i = 0;
    while(y[i] != '\0'){
        x[i] = y[i];
        i++;
    }
    x[i] = '\0';
    // printf("%s, %s\n", x, y );
}

void slices(char * s, int m, int n){

    int i =0;
    while((m + i) < n){
        s[i] = s[m+i];
        i++;
    }
    s[i] = '\0';


}

int myStrLen(char * s){
    int i =0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

void encrypt(char *c){
    
    char * pnt = c;
    while(*pnt != '\0'){
        *pnt = *pnt +1;
        pnt++;
    }
    // int i = 0;
    // while(c[i] != '\0'){
    //     c[i] = c[i] + 1;
    //     i++;
    // }
    // c[i] = '\0';
}

void decrypt(char *c){
    
    // char * pnt = c;
    // while(*pnt != '\0'){
    //     *pnt = *pnt - 1;
    //     pnt++;
    // }
    int i = 0;
    while(c[i] != '\0'){
        c[i] = c[i] - 1;
        i++;
    }
    c[i] = '\0';
}

int main(){

    char s1[] = "Sample text ggg";
    char * s2 = "Another string";
    char s3[] = "This is another text";
    char s4[] = "abcd";


    printf("Character is present result: %s \n", check_c("Test", 'S'));
    printf("Character is present result: %s \n", check_c(s1, 'S'));
    printf("Character is present result: %s \n", check_c(s2, 'z'));
    
    printf("Character count: %d \n", count_c("Me Rohit", 'e'));
    printf("Character count: %d \n", count_c(s1, 'g'));
    printf("Character count: %d \n", count_c(s2, 'z'));


    
    printf("\nString length: %d \n", myStrLen("Thissd poc"));
    printf("\nString length: %d \n", myStrLen(s1));
    printf("\nString length: %d \n", myStrLen(s2));


    // printf("Enter the string: ");
    // char t[30];
    // scanf("%s", &t);
    // printf("string is %s", t);


    printf("%s\n", s3);
    slices(s3, 5, 9);
    printf("%s\n", s3);
    
    printf("s1 and s2 are: %s, %s \n", s1, s2);
    myStrCpy(s1, s2);
    printf("s1 and s2 are: %s, %s \n", s1, s2);
    
    printf("s4 is: %s\n", s4);
    encrypt(s4);
    printf("s4 is: %s\n", s4);
    decrypt(s4);
    printf("s4 is: %s\n", s4);

    return 0;
}
