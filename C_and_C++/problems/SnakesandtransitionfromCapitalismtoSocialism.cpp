#include <climits>
#include <utility>
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

ll MOD = 998244353;
double eps = 1e-12;

#define inp32(v) for(int &i32 : v) cin>>i32
#define inp64(v) for(ll &i64 : v) cin>>i64
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

vector<pair<int, int>> neighbours = {
	{-1, 1},
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
	{-1, 0},
};

bool isValid(int x, int y, int eX, int eY){
	return x >= 0 and y >= 0 and x < eX and y < eY;
}

void bfs(){



	int n, m;
	cin>>n>>m;

	vector<vector<int>> graph(n+1, vector<int>(m+1, 0));
	vector<vector<int>> visited(n+1, vector<int>(m+1, 0));
	vector<vector<int>> level(n+1, vector<int>(m+1, 0));
	
	int mx = INT_MIN;
	int ans = 0;

	queue<pair<int, int>> q;


	for(int i = 0; i< n; i++){
		for(int j = 0; j< m; j++){
			cin>>graph[i][j];
			mx = max(graph[i][j], mx);
		}
	}


	
	for(int i = 0; i< n; i++){
		for(int j = 0; j< m; j++){
			if(graph[i][j] == mx){

				q.push({ i, j });
				visited[i][j] = 1;
				level[i][j] = 0;
			}
		}
	}



	while (!q.empty()) {
		auto parent = q.front();
		int parentX = parent.first;
		int parentY = parent.second;

		q.pop();

		for(auto p : neighbours){
			int childX = p.first + parentX;
			int childY = p.second + parentY;

			if(!isValid(childX, childY, n, m)) continue;
			if(visited[childX][childY]) continue;

			q.push({ childX, childY });
			visited[childX][childY] = true; 
			level[childX][childY] = level[parentX][parentY] + 1;
			ans = max(ans, level[childX][childY]);

		}
	}

	std::cout << ans << std::endl; 
}

void solve(){
	bfs();
}

int32_t main() {
	clock_t _t = clock();

	#ifndef ONLINE_JUDGE
	freopen("/home/rohits/mydata/code/C_and_C++/competitive_programming/inputf.in", "r", stdin);
	/* freopen("/home/rohits/mydata/code/C_and_C++/competitive_programming/outputf.in", "w", stdout); */
	#endif

	fast_cin();
	ll t;
	cin >> t;
	while(t--) {
		solve();
	}

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

