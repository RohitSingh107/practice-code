# include <iostream>
# include <iomanip>
using namespace std;


int main(){

    const float a = 3.14;
    cout<<"The value of a was:"<<endl;
    // a = 45;
    // cout<<a;
    int b = 3, c = 78, d = 123;
    cout<<"The value of a without setw is: "<<b<<endl;
    cout<<"The value of a without setw is: "<<c<<endl;
    cout<<"The value of a without setw is: "<<d<<endl;
    
    cout<<"The value of a with setw is: "<<setw(4)<<b<<endl;
    cout<<"The value of a with setw is: "<<setw(4)<<c<<endl;
    cout<<"The value of a with setw is: "<<setw(4)<<d<<endl;

    // Operator Precedence

    cout<<a+((d/c)*b);



}