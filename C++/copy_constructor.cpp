#include<iostream>
using namespace std;

class Number{
    private:
        int a = 0;
    public:
        Number(){}
        Number(int num){
            a = num;
        }
        // When no copy constructor is given, compiler provide it's own copy constructor
        Number(Number &obj){
            cout<<"Copy constructor called"<<endl;
            a = obj.a;
        }

        void display(){
            cout<<"The numer for this object is "<< a <<endl;
        }
};


int main(){

    Number x = Number(5);
    x.display();

    Number y, z(45), z2;

    y.display();
    z.display();

    Number z1 = Number(z);
    z1.display();

    z2 = z;
    z2.display();

    Number z3 = z;
    z3.display();

    

    
    return 0;
}