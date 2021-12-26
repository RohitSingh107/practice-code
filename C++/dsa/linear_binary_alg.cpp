#include<iostream>
using namespace std;


int linearSearch(int arr[],int size, int element){
    
    for(int i = 0; i < size; i++){
        if (arr[i] == element){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size -1;

    while(low<= high){
        mid = (low + high)/2;
        if (arr[mid] == element){
            return mid;
        }
        else if (element < arr[mid]){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
    
}


int main(){
    
    int arr1[] = {1, 3 , 5, 4,5,4,3,68,4,14,5,4};
    int size = sizeof(arr1)/sizeof(int);
    // cout<<sizeof(arr)<<endl;
    // cout<<sizeof(int)<<endl;
    int searchIndex = linearSearch(arr1, size, 68);
    cout<<"Integer found at index "<<searchIndex<<endl;

    int arr2[] = {4,5,5,6,9,45,78,778, 4597};
    int size2 = sizeof(arr2)/sizeof(int);

    int searchIndexBinary = binarySearch(arr2, size2, 5);
    cout<<"Integer found at index "<<searchIndexBinary<<endl;



    
    return 0;
}