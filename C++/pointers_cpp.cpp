# include <iostream>
# include <string>
using namespace std;
void inceament(int *x){
    (*x)++;
}

int main(){

    string a = "Rohit";
    string* b;
    b = &a;
    cout<<"The value of a is "<<a<<endl;
    cout<<"The value of a is "<<*b<<endl;
    cout<<"The address of a is "<<&a<<endl;
    cout<<"The address of a is "<<b<<endl;
    cout<<"The address of a + 1 is "<<b+1<<endl;
    // cout<<"Value at a+ 1 is "<<*(b+1)<<endl;

    cout<<"Pointer to Pointer"<<endl;

    string**c = &b;

    cout<<"The address of b is "<<&b<<endl;
    cout<<"The address of b is "<<c<<endl;
    cout<<"The value at adress c is "<<*c<<endl;
    cout<<"The value at adress value_at (value_at(c)) "<<**c<<endl;

    
    cout<<"changing value using pointer"<<endl;
    **c = "Singh";
    cout<<"The value at adress value_at (value_at(c)) "<<**c<<endl;

    // Arrays and pointers

    cout<<"Arrays and Pointers"<<endl;

    int ar[10];
    ar[0] = 2;
    ar[1] = 4;
    cout<<"ar: "<<ar<<endl;
    cout<<"&ar[0]: "<<&ar[0]<<endl;
    cout<<"*ar: "<<*ar<<endl;
    cout<<"ar+1: "<<ar +1<<endl;
    cout<<"&ar[1]: "<<&ar[1]<<endl;
    cout<<"*(ar+1): "<<*(ar +1)<<endl;
    
    
    cout<<"Using pointers"<<endl;

    

    int k = 4;
    cout<< k<<endl;
    inceament(&k);
    cout<< k<<endl;











    return 0;
}