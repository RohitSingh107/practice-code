#include <bits/stdc++.h>
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <cstring>
// #include <chrono>
// #include <complex>
#define el endl
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
// #define mem(a,val) memset(a,val,sizeof(a))



using namespace std;

bool uf(vector<string> &lucky, string s){
    bool ans = false;
    for(string st : lucky){

        ans = ans || (s.find(st) != std::string::npos);
    }
    return ans;
}
    

void solution(void){
    
    int k, n;
    cin>>k>>n;
    vector<string> lucky(k);
    
    // vector<string> pillow(n);
    for(int i = 0; i< k; i++){
        // string s;
        cin>>lucky[i];
    }
    for(int i = 0; i< n; i++){
        string s;
        cin>>s;
        if(s.size() >= 47 || uf(lucky ,s)){
            cout<<"Good"<<el;
        }
        else{
            cout<<"Bad"<<el;
        }
        // cin>>pillow[i];
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    // cin>>T;
    T = 1;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--){
        solution();
    }
    return 0;
}