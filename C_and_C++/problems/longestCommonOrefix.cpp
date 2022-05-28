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

string solve(string ans, string s){
	string result;
	int n1 = ans.size();
	int n2 = s.size();
	for(int i = 0; i<n1 && i<n2; i++){
		if(ans[i] != s[i]){
			break;
		}
		result.push_back(s[i]);
	}
	return result;
}

int main()
{
	int n = 4;
	string arr[n] = {"geeksforgeeks", "geeks", "geek", "geezer"};
	
	string ans = arr[0];

	for(int i = 0; i< n; i++){
		ans = solve(ans, arr[i]);
	}
	cout<<ans<<el;

    return 0;
}