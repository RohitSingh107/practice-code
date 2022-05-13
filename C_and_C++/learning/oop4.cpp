#include<iostream>
using namespace std;

class Employee {
    private:
        int id;
        static int count;
    
    public:

        void setData(void){
            cout<<"Enter the id: "<<endl;
            cin>>id;
            count++;
        }

        void getData(void){
            cout<<"The id of this employee is: "<<id<<" and this is employee number: "<<count<<endl;
        }

        static void getCount(void){
            cout<<"Total Employees are "<<count<<endl;
        }


};

int Employee :: count; // default value is 0

int main(){

    Employee rohit, dash, apple;

    rohit.setData();
    rohit.getData();
    Employee :: getCount();
    
    dash.setData();
    dash.getData();
    Employee :: getCount();

    apple.setData();
    apple.getData();
    Employee :: getCount();
    
    return 0;
}