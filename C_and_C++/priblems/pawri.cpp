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

	for(int i = 0; i<= n-5; i++){
		if(s[i] == 'p' and s[i+1] == 'a' and s[i+2] == 'r' and s[i+3] == 't' and s[i+4] == 'y'){
			s[i+2] = 'w';
			s[i+3] = 'r';
			s[i+4] = 'i';
		}
	}
	cout<<s<<endl;

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