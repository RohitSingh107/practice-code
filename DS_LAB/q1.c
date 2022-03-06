#include<stdio.h>



void findTriplet(int arr[], int n, int num){
    for(int i = 0; i<n -2; i++){
        for(int j = i+1; j<n -1; j++){
            for(int k = j+1; k< n; k++){
                if(arr[i] + arr[j] + arr[k] == num){
                    printf("Triplet is %d %d %d\n", arr[i], arr[j], arr[k]);
                    return;
                }
            }
        }
    }
    printf("Triplet doen't exist.\n");
}



int main(){


    int n = 8;
    int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
    int num = 6;
    findTriplet(arr, n, num);

    return 0;
}