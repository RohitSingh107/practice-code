#include<stdio.h>
// #include<stdlib.h>
// #include<string.h>






int main(){

    int n = 5;
    int arr[5] = {3, 1, 3, 2, 5};
    int perfect_arr[5];

    int min = arr[0];
    int max = arr[0];

    for(int i = 0; i< n; i++){
        if(min > arr[i]){
            min = arr[i];
        }

        if(max < arr[i]){
            max = arr[i];
        }
    }

    for(int i = 0; i<n; i++){
        perfect_arr[i] = min + 1;
    }


    return 0;
}