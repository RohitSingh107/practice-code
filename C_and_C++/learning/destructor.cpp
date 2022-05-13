#include<iostream>
using namespace std;
int count=0;
class Num{
    public:
        Num(){
            count++;
            cout<<"This is the time when contructor is called for object number: "<<count<<endl;
        }
        ~Num(){
            cout<<"This is the time when destrucotr is called for object number: "<<count<<endl;
            count--;
        }
};

int main(){
    cout<<"We are in main function"<<endl;
    cout<<"creating first object"<<endl;
    Num n1;
    {
        cout<<"Entering this block"<<endl;
        cout<<"creating two more object"<<endl;
        Num n2, n3;
        cout<<"Exiting the block"<<endl;

    }
    cout<<"Back to main"<<endl;
    
    
    return 0;
}