#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> vv;

void generate(vector<int> &comb, vector<int> &v, int curr, int b){

    if(curr == v.size()){
        if(b == 0){
            vv.push_back(comb);
        }
        return;
    }



    // cout<<v[curr]<<endl;
    // Picks the nums[p]
    if(v[curr] <= b){
        comb.push_back(v[curr]);
        generate(comb, v, curr, b - v[curr]);
        comb.pop_back();
    }

    // Not pick the nums[p]
    generate(comb, v, curr+1, b);
}


int main(){ 


    int n = 4;
    // vector<int> v = {7,2,6,5};
    vector<int> v = {8,1,8,6,8};
    // remove(v);
    unordered_set<int> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());

    sort(v.begin(), v.end());
    int b = 12;
    vector<int> empty;
    generate(empty,v, 0, b);

    sort(vv.begin(), vv.end());

    
    for(auto vi : vv){
        for(int i : vi){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // cout<<vv[0].size()<<endl;
    // for(int i =0; i<)

    return 0;
}