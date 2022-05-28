#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    
    set<char>ans;
    for(char c : s){
        ans.insert(c);
    }
    cout<<s.size() - ans.size()<<endl;
    
    return 0;
}