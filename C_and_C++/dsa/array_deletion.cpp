#include<iostream>
using namespace std;

void display(int arr[], int s){
    for (int i = 0; i<s; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Current Size: "<<s<<endl;

}

int indDeletion(int arr[], int *size, int index){

    if (*size <= 0 || index >= *size){
        cout<<"Deletion failed"<<endl;
        return -1;
    }


    for (int i = index; i<= *size - 2; i++){
        arr[i] = arr[i+1]; 

    }
    *size = *size - 1;
    cout<<"Deletion sucessfull: "<<endl;
    display(arr, *size);
    return 1;
}

int main(){
    
    int arr[100] = {1,2,6,87};

    int size = 4;

    display(arr, size);

    indDeletion(arr, &size, 1);

    indDeletion(arr, &size, 2);

    indDeletion(arr, &size, 45);

    indDeletion(arr, &size, 1);

    indDeletion(arr, &size, 0);

    indDeletion(arr, &size, 0);



    return 0;
}