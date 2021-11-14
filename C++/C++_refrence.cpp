#include<iostream>
using namespace std;

void increament(int &n, int n1){
    n++;
    n1++;
}

void array_change_without_reffrence(int arr[]){
    arr[0] = 10;
}

int main(){
    

    int a = 3;
    int b = 5;
    cout<< a<< endl;
    increament(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    
    cout<<"Arrays"<<endl;
    int c[10];
    c[0] = 7;
    
    cout<<c[0]<<endl;
    array_change_without_reffrence(c);
    cout<<c[0]<<endl;





    return 0;
}