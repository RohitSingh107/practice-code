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

int ans = 0;

/* int currcon = 0; */

void dfs(bool parent, int currcon, int m, int vertex, vector<vector<int>> graph, vector<bool> visited, vector<int> cats_location){

	/* std::cout << "Here1 " << vertex << " " << graph[vertex].size() << std::endl; */	

	/* std::cout << "Entered " << vertex << " " << currcon << " " << ans << std::endl; */

	if(vertex == 1) parent = true;
	if(cats_location[vertex] and parent){
		currcon++;
	}
	if(graph[vertex].size() == 0 and currcon <= m){
		ans++;
	}

	std::cout << "Entered " << vertex << " " << parent <<" " << currcon << " " << ans << std::endl;

	if(cats_location[vertex]){
		parent = true;
	}
	else{
		parent = false;
		currcon = 0;
	}




	if(currcon > m){
		return;
	}
	
	visited[vertex] = true;
	for(int child : graph[vertex]){

		/* std::cout << "child is " << child << std::endl; */
		/* leaf = false; */

		if(visited[child]) continue;	

		dfs(parent, currcon, m, child, graph, visited, cats_location);
	}
	/* std::cout << "Here3 " << vertex << " " << graph[vertex].size() << std::endl; */	
}

void solve(){
	int n, m;
	cin>>n>>m;

	vector<int> cats_location(n+1);
	vector<vector<int>> graph(n+1);
	vector<bool> visited(n);

	for(int i = 1; i< n+1; i++){
		cin>>cats_location[i]; 
	}


	for(int i = 1; i< n-1+1; i++){
		int u, v;
		cin>>u>>v;

		graph[u].push_back(v);
	}
	dfs(false, 0, m, 1, graph, visited, cats_location);
	std::cout << ans << std::endl;
	/* std::cout << graph[1].size() << std::endl; */
	/* std::cout << graph[3][0] << " " << graph[3][1] << std::endl; */
	/* for(auto v : graph){ */
	/* 	for(auto i : v){ */
	/* 		std::cout << i << " "; */
	/* 	} */
	/* 	std::cout << std::endl; */
	/* } */
}

int32_t main() {

	#ifndef ONLINE_JUDGE
	freopen("/home/rohits/mydata/code/C_and_C++/competitive_programming/inputf.in", "r", stdin);
	freopen("/home/rohits/mydata/code/C_and_C++/competitive_programming/outputf.in", "w", stdout);
	#endif

	fast_cin();
	ll t = 1;
	while(t--) {
		solve();
	}
	return 0;
}

