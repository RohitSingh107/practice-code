#include<stdio.h>

int linearSearch(int * a, int size, int element){

    for(int i = 0; i< size; i++){
        if(a[i] == element){
            return i;
        }
    }
    return -1;
}

// int binarySearch(int * a, int size, int element){
//     int l = 0;
//     int r = size - 1;
//     while(l <= r){
//         int m = (l + r) / 2;
//         if(a[m] == element){
//             return m;
//         }
//         else if(element < a[m]){
//             r = m - 1;
//         }
//         else{
//             l = m + 1;
//         }

//     }
//     return -1;
// }




int main(){

    int arr1[] = {1, 3 , 5, 4,5,4,3,68,4,14,5,4};
    int size = sizeof(arr1)/sizeof(int);
    
    int arr2[] = {4,5,5,6,9,45,78,778, 4597};
    int size2 = sizeof(arr2)/sizeof(int);

    int resLS = linearSearch(arr1, size, 68);
    if(resLS >= 0){
        printf("Element found at index %d\n", resLS);
    }
    else{
        printf("Element not found\n");
    }

    // int resBS = binarySearch(arr2, size2, 78);
    // if(resLS >= 0){
    //     printf("Element found at index %d\n", resBS);
    // }
    // else{
    //     printf("Element not found\n");
    // }
    


    return 0;
}