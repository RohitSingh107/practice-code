#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n, m;
        cin>>n>>m;
        
        unordered_map<long long int,int> s;
        for(int i = 0; i< n; i++){
            long long int c;
            cin>>c;
            s[c] = 1;
        }
        for(int j = 0; j< m; j++){
            long long int c;
            cin>>c;
            if(s[c] != 1){
                cout<<"NO"<<endl;
                s[c] = 1;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }


    return 0;
}