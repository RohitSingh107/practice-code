#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    if(n % 2 != 0){
        cout<<"-1"<<endl;
    }
    else{
        cout<< n <<" "<< n + (n/2)<<endl;
        cout<< n + (n/2)<<" "<< n<<endl;
        cout<< n <<" "<< n -(n/2) <<endl;
        cout<<n - (n/2)<<" " << n<<endl;
    }


    return 0;
}