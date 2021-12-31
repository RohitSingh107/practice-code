#include<iostream>
using namespace std;

typedef struct employee
{
    /* data */
    int eId;
    char favChar;
    float salary;
} ep;

union money
{
    /* data */
    int rice;
    char  car;
    float pounds;
};



int main(){
    
    cout<<"Employee structure"<<endl;
    
    ep rohit;
    
    struct employee dash;
    struct employee apple;
    
    rohit.eId = 10;
    rohit.favChar = 'Q';
    rohit.salary = 100;

    cout<<"The value is "<<rohit.eId<<endl;
    cout<<"The value is "<<rohit.favChar<<endl;
    cout<<"The value is "<<rohit.salary<<endl;


    cout<<"Money Union"<<endl;
    union money m1;
    m1.rice = 34;
    m1.car = 'c';
    cout<<m1.rice<<endl;
    cout<<m1.car<<endl;

    cout<<"Enum meal"<<endl;
    enum Meal{ breakfast, lunch, dinner};
    cout<<breakfast<<endl;
    cout<<lunch<<endl;
    cout<<dinner<<endl;

    Meal mymeal = lunch;
    cout<<mymeal<<endl;
    cout<<(mymeal == 1)<<endl;

    
    return 0;
}