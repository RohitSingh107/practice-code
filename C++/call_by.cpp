#include<iostream>
using namespace std;

int sum(int a, int b){
    int c = a + b;
    return c;
}

// This will not swap a and b
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

// Calll by reference using pointer
void swapPointer(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Calll by reference using C++ reference Variables
void swapReferenceVar(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;

}

int main(){

    int x=4, y=5;
    
    cout<<"The sum of 4 and 5 is "<<sum(4,5)<<endl;

    // swap(x,y);
    // swapPointer(&x, &y); //This works
    swapReferenceVar(x,y);
    cout<<"The value of x is "<<x<<" and value of y is "<<y<<endl;

    return 0;
}