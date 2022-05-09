#include<bits/stdc++.h>
using namespace std;


vector<string> vs;

void generate(string &s, int open, int  close){

    if(open == 0 and close == 0){
        vs.push_back(s);
        return;
    }

    if(open>0){
        s.push_back('(');
        generate(s, open -1, close);
        s.pop_back();
    }

    if(close>0 and open < close){
        s.push_back(')');
        generate(s, open, close-1);
        s.pop_back();
    }
}


int main(){ 

    int n = 1;
    string s = "";

    generate(s, n,n);

    for(auto i : vs){
        cout<<i<<endl;
    }

    return 0;
}