#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){

        set<string> s;

        int n;
        cin>>n;
        while(n--){
            string name;
            cin>>name;
            s.insert(name);
        }
        for(auto p : s){
            cout<<p<<endl;
        }
    }


    return 0;
}