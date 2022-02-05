#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {2,3,5,99,5};

    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<< " ";
    }
    cout<<endl;
    vector<int> :: iterator it = v.begin();
    // cout<< (*(it+1))<<endl;
    for(it = v.begin(); it != v.end(); ++it){
        cout<< *it << endl;
    }

    cout<<"Seperate"<<endl;

    vector<pair<int,int>> vp = {{4,6}, {7,67}, {9,3}, {45,36}};

    // for(vector<pair<int,int>> :: iterator it = vp.begin(); it != vp.end(); it++){
    //     cout<<(*it).first<<" "<<it->second<<endl; 
    // }
    //Both are equal
    for(auto it = vp.begin(); it != vp.end(); it++){
        cout<<(*it).first<<" "<<it->second<<endl; 
    }

    //C++ 11 afterwards
    cout<<"Using C++ 11 feature"<<endl;
    for(int value : v){
        cout<<value<<" ";
    }
    cout<<endl;

    cout<<"Using C++ 11 feature"<<endl;
    for(int &value : v){
        value++;
        cout<<value<<" ";
    }
    cout<<endl;


    return 0;
}