#include<bits/stdc++.h>
using namespace std;


int main(){

    int t; cin>>t;
    while(t--){
        string x, y;
        cin>>x>>y;
        string z = "";
        for(int i = 0; i<5; i++){
            if(x[i] == y[i]){
                z = z + "G";
            }
            else{
                z = z + "B";
            }
        }
        cout<<z<<endl;
    }
    
    return 0;
}