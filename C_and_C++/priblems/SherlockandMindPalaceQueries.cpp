#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans =0;
        for(int i = 1; i<= n/2; i++){
            if(n % i == 0){
                ans++;
            }
        }
        cout<<ans + 1<<endl;
    }
    
    return 0;
}