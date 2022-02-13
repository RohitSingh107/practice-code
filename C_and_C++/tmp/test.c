#include <stdio.h>

void f(int arr[]){
    for(int i = 0; i< 6; i++){
        printf(" %d ", arr[i]);
    }
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

    return 0;

}
