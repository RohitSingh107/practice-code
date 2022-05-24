#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <initializer_list>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define el endl
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int cnt = 1;

template<class T>
void toConsole(T content){
	cout<<"Log No. "<< cnt <<" | "<<content<<endl;
	cnt++;
}

template<class T>
void toConsole(vector<T> v){
	cout<<"Log No. "<< cnt<<" | <vector> ";
	for(auto e : v){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	cnt++;
}

template<class T>
void toConsole(set<T> s){
	cout<<"Log No. "<< cnt<<" | <set> ";
	for(auto e : s){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	cnt++;
}

template<class T>
void toConsole(unordered_set<T> us){
	cout<<"Log No. "<< cnt<<" | <unordered_set>";
	for(auto e : us){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	cnt++;
}

template<class KEY, class VAL>
void toConsole(map<KEY, VAL> m){
	cout<<"Log No. "<< cnt<<" | <map>" << endl;
	for(auto p : m){
		std::cout << "\t\t" << p.first << " " << p.second << std::endl;
	}
	std::cout << "\t</map>" << std::endl;
	cnt++;
}

template<class KEY, class VAL>
void toConsole(unordered_map<KEY, VAL> m){
	cout<<"Log No. "<< cnt<<" | <unordered_map>" << endl;
	for(auto p : m){
		std::cout << "\t\t" << p.first << " " << p.second << std::endl;
	}
	std::cout << "\t</unordered_map>" << std::endl;
	cnt++;
}

template<class T>
void toConsole(std::initializer_list<T> list){
	cout<<"Log No. "<< cnt<<" | ";
	for(auto e : list){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	cnt++;
}

int solve()
{
    int n;
    cin >> n;
    v32 v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vv32 ppd(n + 1, vector<int>(7));
    ppd[0][0] = 1;                                  
    for (int i = 0; i < n; i++)
    {
        int x = (int)to_string(v[i]).size();
		/* std::cout <<"l is " << l << std::endl; */
        int y = 1;
        while (x--)
            y *= 10; 
        for (int j = 0; j < 7; j++)
        {
            int z = (j * y + v[i]) % 7;                
            ppd[i + 1][j] = (ppd[i + 1][j] + ppd[i][j]) % MOD;     
            ppd[i + 1][z] = (ppd[i + 1][z] + ppd[i][j]) % MOD; 
        }
    }
    cout << (ppd[n][0] - 1 + MOD) % MOD << el; 
    return 0;
}


int32_t main() {

	#ifndef ONLINE_JUDGE
	freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/inputf.in", "r", stdin);
	freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/outputf.in", "w", stdout);
	#endif

	fast_cin();
	ll t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

