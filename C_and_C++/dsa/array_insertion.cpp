#include<iostream>
using namespace std;

void display(int arr[], int s){
    for (int i = 0; i<s; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int indInsertion(int arr[], int *size, int element, int capacity, int index){
    if (*size>=capacity){
        cout<<"Insertion failed."<<endl;
        return -1;
    }
    for (int i = *size -1; i>=index; i--){
        arr[i+1] = arr[i]; 

    }
    arr[index] = element;
    *size = *size + 1;
    cout<<"Insertion sucessfull: "<<endl;
    display(arr, *size);
    return 1;
}

int main(){
    
    int arr[100] = {1,2,6,87};

    int size = 4;

    display(arr, size);

    indInsertion(arr, &size, 10, 100, 1);

    indInsertion(arr, &size, 17, 100, 3);

    int sizep = 100;

    indInsertion(arr, &sizep, 11, 100, 3);




    return 0;
}