#include<iostream>
#include<cmath>
using namespace std;

class BankDeposit{
    int principal;
    int years =1;
    float rate;
    float returnValue;
    
    public:
        BankDeposit(){};
        BankDeposit(int p, int y, float r){
            principal = p;
            years = y;
            rate = r;
            returnValue = principal * pow(rate + 1, years);
            // for (int i = 0; i < y; i++){
                // returnValue = returnValue * (1 + r);
            // }
        }
        
        BankDeposit(int p, int y, int r){
            principal = p;
            years = y;
            rate = float(r)/100;
            returnValue = principal * pow(rate + 1, years);
            // for (int i = 0; i < y; i++){
                // returnValue = returnValue * (1 + r);
            // }
        }

        void show(){
            cout<<endl<<"Principal amount was "<<principal
                << ", Return value after "<<years
                << " years is "<<returnValue<<endl;
        } 
        
};

int main(){

    BankDeposit bd1, bd2, bd3;
    int p, y;
    float r;
    int R;

    cout<<"Enter the value of p y and r"<<endl;
    cin>>p>>y>>r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();


    cout<<"Enter the value of p y and R"<<endl;
    cin>>p>>y>>R;
    bd2 = BankDeposit(p, y, R);
    bd2.show();


    return 0;
}