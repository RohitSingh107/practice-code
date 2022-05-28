#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;

    map<int, multiset<string>, std::greater<int>> m;

    for(int i = 0; i< N; i++){
        string name;
        int marks;
        cin>>name;
        cin>>marks;
        m[marks].insert(name);
    }

    for(auto p : m){
        for(string val : p.second){
            cout<<val<<" "<<p.first<<endl;
        }
    }
    return 0;
}