#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    // cout<<"Enter n :";
    cin>>n;

    map<string, int> m;

    while(n--){
        string s;
        cin>>s;
        auto it = m.find(s);
        if(it == m.end()){
            m[s] = 1;
            cout<<"OK"<<endl;;
        }
        else{
            m[s] = m[s] + 1;
            string nu = s.append(to_string(m[s] -1));
            m[nu] = 0;
            cout<<nu<<endl;
        }
   
    }

    return 0;
}