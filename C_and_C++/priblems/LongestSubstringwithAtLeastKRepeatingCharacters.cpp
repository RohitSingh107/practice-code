#include<bits/stdc++.h>
using namespace std;


int lss(string s, int k){
    int n = s.size();
    if(k <= 1){
        return n;
    }
    if(k > n || n == 0){
        return 0;
    }
    unordered_map<char,int> counts;
    for(char c : s){
        counts[c] +=1; 
    }
    int l = 0;
    while(l<n && counts[s[l]] >= k){
        l++;
    }
    if(l >= n-1){
        return l;
    }
    int ss1 = lss(s.substr(0, l), k);
    
    while(l<n && counts[s[l]] < k){
        l++;
    }
    int ss2 = lss(s.substr(l), k);
    return max(ss1, ss2);
}

int main(){

    int k = 2;
    // string s = "aaabb";
    string s = "ababbc";

    cout<<lss( s, k)<<endl;
    // cout<<s.substr(0, 3)<<endl;
    
    return 0;
}