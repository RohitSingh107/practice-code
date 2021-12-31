# include <iostream>
using namespace std;

int main(){

    int age;
    cout<<"Enter your age"<<endl;
    cin>>age;
    
    switch (age)
    {
    
    case 12:
        cout << "You are 12 years old";
        break;
    case 18:
        cout << "You are 18 years old";
        break;
    default:
        cout << "You are neither 12 nor 18 years old";

    }



    return 0;
}