#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
}

int main(){
    int t; cin>>t;
    vector<pair<string, int>> vp;
    while(t--){
        pair<string, int> p;
        cin>>p.first>>p.second;
        vp.push_back(p);
    }

    sort(vp.begin(), vp.end(), cmp);

    for(auto it : vp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    return 0;
}