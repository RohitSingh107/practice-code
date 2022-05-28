#include<iostream>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long f = 1;
        for (int i=0; i<n; i++){
            int j;
            cin>>j;
            f = f*j;

        }
        int leas_sig = f % 10;
        if (leas_sig == 2 || leas_sig == 3 || leas_sig == 5){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}