#include<iostream>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int digits_sum = 0;
        while(n > 0){
            int last_digit = n % 10;
            digits_sum = digits_sum + last_digit;
            n = n/10;
        }

        cout<<digits_sum<<endl;
    
    }



    return 0;
}