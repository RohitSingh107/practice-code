#include <stdio.h>

void f(int arr[]){
    for(int j = 0; j< 6; j++){
        printf(" %d ", arr[j]);
    }
}

int mf(int a, int b){
    int c = 0;
    for(int k = 0; k< 4; k++){
        c = c + a + b;
    }
    return c;
}


int main(){

    int ar[] = {4,7,6,9,45,36};

    f(ar);

    printf("\n");

    int i = 0;
    while(i< 6){
        printf(" %d ", ar[i]);
        i++;
    }

    mf(7, 3);

    return 0;

}
