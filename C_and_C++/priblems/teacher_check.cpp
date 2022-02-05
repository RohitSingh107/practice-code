#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int q;
    cin>>q;
    
    map<string, int> m;
    for(int i =0; i< q; i++){
        int type;
        string name;
        cin>>type;
        cin>>name;
        // int marks;
        if(type == 1){
            int marks;
            cin>>marks;
            m[name] = m[name] + marks;
        }
        else if(type == 2){
            m.erase(name);
        }
        else if(type == 3){
            auto it = m.find(name);
            if(it == m.end()){
                cout<<0<<endl;
            }
            else{
                cout<<it->second<<endl;
            }
        }
    }
    
    return 0;
}



