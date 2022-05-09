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
ll MOD = 998244353;
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

int n, cows;
const int N = 1e5+10;
int positions[N];

bool canPlace(int dist){
	int lastpos = -1;
	int cow_ct = cows;
	for (int i = 0; i < n; ++i) {
		if(positions[i] - lastpos>= dist || lastpos == -1){
			cow_ct--;
			lastpos = positions[i];
		}
	}
	return cow_ct == 0;
}

void solve(){
	cin>>n>>cows;
	for(int i = 0; i<n; i++){
		cin>>positions[i];
	}
	sort(positions, positions + n);
	int lo = 0, hi = 1e9, mid;
	while(hi - lo > 1){
		mid = (lo + hi)/2;
		if(canPlace(mid)){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	if(canPlace(hi)){
		cout<<hi<<endl;
	}
	else{
		cout<<lo<<endl;
	}
}
int32_t main() {

	#ifndef ONLINE_JUDGE
	freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/inputf.in", "r", stdin);
	freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/outputf.in", "w", stdout);
	#endif

	fast_cin();
	ll t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}

