#include <bits/stdc++.h>
using namespace std;

int main(){
    map<pair<string, string>, vector<int> > m;

    int n; cin>>n;
    for(int i = 0; i< n; ++i){
        string fn, ln;
        int ct;
        cin>>fn>>ln>>ct;
        for(int j = 0; j<ct; ++j){
            int x;
            cin>>x;
            m[{fn,ln}].push_back(x);
        }
    }

    for(auto &p : m){
        cout<<p.first.first << " "<<p.first.second<<endl;
        cout<<p.second.size()<<endl;
        for(int &val : p.second){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}