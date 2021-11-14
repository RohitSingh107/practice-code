#include<iostream>
#include <cstring>
using namespace std;

// Inline Function
inline int product(int a, int b){
    return a*b;
}

// static variables
int sum(int a, int b){
    static int c=0;
    c = c+1;
    return a*b+c;
}


// Function with default values
int money_received(int currentMOney, float factor=1.04){
    return currentMOney * factor;
}


// functions with immutable arguments
int srtlen(const char *p){
    return sizeof(p);
}

// Function Overloading
int sumf(int a, int b){

    cout<<"Usinf function 2 args"<<endl;

    return a+b;
}
int sumf(int a, int b, int c){

    cout<<"Usinf function 3 args"<<endl;

    return a+b+c;
}


int volume(double r, int h){ // Cylinder
    return 3.14*r*r*h;
}
int volume(int a){ // Cube
    return a*a*a;
}
int volume(int l, int b, int h){ // Cuboid
    return l*b*h;
}

int main(){
    // int a, b;
    // cout<<"Enter Values"<<endl;
    // cin>>a>>b;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    
    int money = 10000;

    cout<<"With default value "<<money_received(money)<<endl;
    cout<<"Without default value "<<money_received(money, 3.4)<<endl;
    
    char d = 'K';
    cout<<strlen(&d)<<endl;

    cout<<"The sum of 3 and 5 is "<<sumf(3,5)<<endl;
    cout<<"The sum of 3, 7 and 6 is "<<sumf(3,7,6)<<endl;

    cout<<"The vouleme of cuboid is "<<volume(3,7,6)<<endl;
    cout<<"The vouleme of cylinder is "<<volume(3,6)<<endl;
    cout<<"The vouleme of cube is "<<volume(8)<<endl;

    return 0;
}