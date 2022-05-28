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


void solution(void){
	string s;
	cin>>s;
	int n = s.size();
	if(n<=2){
		cout<<"YES"<<el;
	}
	else{
		if(s[0] == s[n-1]){
			cout<<"YES"<<el;
		}
		else{
			// cout<<"NO"<<el;
			if((s.substr(1,n-2) + s[0]) == (s[n-1] + s.substr(1,n-2))){
				cout<<"YES"<<el;
			}
			else{
				cout<<"NO"<<el;
			}
		}
	}
	// cout<<s.substr(1,s.size()-2)<<el;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--){
    	solution();
    }
    return 0;
}