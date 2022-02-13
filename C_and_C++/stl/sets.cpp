#include<bits/stdc++.h>
using namespace std;


void printSet(set<string> s){
    cout<<"Set is ";
    for(string val : s){
        cout<<val<<" ";
    }
    cout<<endl;
}

void printUSet(unordered_set<string> s){
    cout<<"Set is ";
    for(string val : s){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    //multiset<string> s; // Allows dublicate values
    set<string> s;

    s.insert("abc"); //log(n)
    s.insert("xabc"); //log(n)
    s.insert("fabc"); //log(n)
    s.insert("tabc"); //log(n)
    s.insert("tabc"); //log(n)
    s.insert("sabc"); //log(n)

    printSet(s);

    auto it = s.find("sabc");
    if(it != s.end()){
        cout<<(*it)<<endl;
    }

    s.erase("tabc");
    printSet(s);

    unordered_set<string> lo;
    cout<<"Enter the no strings: ";
    int n;
    cin>>n;
    for(int i = 0; i< n; i++){
        cout<<"Enter the string: ";
        string t;
        cin >>t;
        lo.insert(t);
    }
    printUSet(lo);

}
