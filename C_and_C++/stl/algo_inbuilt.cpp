#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<int> v = {2,3,1,-6,7,6};
    int n = 6;
    int a[] = {2,3,1,-6,7,6};

    int min = *min_element(v.begin()+3, v.end());
    cout<<min<<endl;
    int max = *max_element(v.begin(), v.end());
    cout<<max<<endl;

    int sum = accumulate(v.begin(), v.end(),0);
    cout<<sum<<endl;
    
    int ct = count(v.begin(), v.end(),6);
    cout<<ct<<endl;

    auto it = find(v.begin(), v.end(), 3);
    if(it != v.end()){
        cout<<*it<<endl;
    }
    else{
        cout<<"elem not found"<<endl;
    }

    reverse(v.begin(), v.end());
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;

    string s = "abcdefgh";
    reverse(s.begin()+3, s.end());
    cout<<s<<endl;

    auto ptr = find(a, a+n, 2);
    if(ptr != a+n){
        cout<<*ptr<<endl;
    }
    else{
        cout<<"elem not found"<<endl;
    }

    cout<<all_of(v.begin(), v.end(), [](int x){return x > 0;})<<endl;;
    cout<<any_of(v.begin(), v.end(), [](int x){return x > 0;})<<endl;;
    cout<<none_of(v.begin(), v.end(), [](int x){return x > 0;})<<endl;;
    
    return 0;
}
