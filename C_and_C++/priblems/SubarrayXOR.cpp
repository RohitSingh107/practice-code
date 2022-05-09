#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string num){
    int d = 0;
    for(int i = num.size()-1; i >= 0; i--){
        d = d + (num[i] - 48)*pow(2,num.size() -1 -i);
    }
    return d;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n; cin>>n;
        string x;
        cin>>x;
    
        multimap<string, int> m;
        for(int i = 0; i<x.size(); i++){
            for(int j = 0; j < x.size()-i; j++){
                // cout<<x.substr(i, 1+ j)<<endl;
                string y = x.substr(i, 1+ j); 
                m.insert({y, binaryToDecimal(y)});
            }
        }
        int ans = 0;
        for(auto pr : m){
            ans = ans ^ pr.second;
        }
        cout<<ans<<endl;
        }
    return 0;
}