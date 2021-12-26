#include<iostream>
using namespace std;

int sum(int n, int a[]){
    if(n<0){
        return 0;
    }
    return sum(n-1, a) + a[n];
}

int digit_sum(int n){
    if(n==0){
        return 0;
    }
    return (n % 10) + digit_sum(n / 10);
}

int main(){
    
    // int n;
    // cin >> n;
    // int a[n];
    // for(int i = 0; i< n; ++i){
    //     cin>>a[i];
    // }
    // cout<<sum(3, a)<<endl;

    cout<<digit_sum(2)<<endl;

    return 0;
}