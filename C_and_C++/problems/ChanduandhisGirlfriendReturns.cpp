#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return b < a;
}

int main(){
    int t; cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        // vector<int> a(m);
        vector<int> ans;
        // vector<int> b(n);
        for(int i = 0; i< m; i++){
            int j;
            cin>>j;
            ans.push_back(j);
        }
        for(int i = 0; i< n; i++){
            int k;
            cin>>k;
            ans.push_back(k);
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int l : ans){
            cout<<l<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}