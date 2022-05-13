#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        int salary;
    public:
        void setId(void){
            salary = 122;
            cout<<"Enter the id of employee"<<endl;
            cin>>id;
        }
        void getId(void){
            cout<<"The id of this employee is "<<id<<endl;
        }
};


int main(){
    
    // Employee rohit, dot, dash, apple;
    // rohit.setId();
    // rohit.getId();
    Employee company[4];
    for (int i=0; i<4; i++){
        company[i].setId();
        company[i].getId();

    }





    return 0;
}