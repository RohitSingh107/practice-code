#include <climits>
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

/* int ans = INT_MIN; */

/* void dfs(int i, int j, int m, int n, vector<vector<int>> &matrix, int p, int c){ */

/* 	/1* std::cout << "Value of c is " << c << std::endl; *1/ */

/* 	if(i < 0 || i >= m || j < 0 || j >= n){ */
/* 		return; */
/* 	} */

/* 	if(matrix[i][j] <= p){ */
/* 		return; */
/* 	}else{ */
/* 		c++; */
/* 	} */

/* 	ans = max(ans, c); */

/* 		dfs(i, j - 1, m, n,  matrix, matrix[i][j], c); */
/* 		dfs(i - 1, j, m, n,  matrix, matrix[i][j], c); */
/* 		dfs(i, j + 1, m, n,  matrix, matrix[i][j], c); */
/* 		dfs(i + 1, j, m, n,  matrix, matrix[i][j], c); */
/* } */

/* int longestIncreasingPath(vector<vector<int>>& matrix) { */


/* 	int m = matrix.size(); */
/* 	int n = matrix[0].size(); */
   
/* 	for(int k = 0; k< m; k++){ */
/* 		for(int l = 0; l < n; l++){ */
/* 			dfs(k, l, m, n, matrix, INT_MIN, 0); */
/* 		} */
/* 	} */

/* 	return ans; */
/* } */


vector<vector<int>> preSum(205, vector<int>(205, 1));
vector<vector<bool>> visited(205, vector<bool>(205));

int ans = INT_MIN;

void dfs(int i, int j, int m, int n, vector<vector<int>> &matrix, int pi, int pj){


	if(i < 0 || i >= m || j < 0 || j >= n){
		return;
	}

	/* std::cout << "brfore " << matrix[i][j] << " "<< matrix[pi][pj] << " " <<  preSum[i][j]<< std::endl; */

	/* std::cout << "Value of i and j and node and parent and preSum is  is " << i << " " << j << " " << matrix[i][j] << " " << matrix[pi][pj] << " " << preSum[pi][pj] << std::endl; */
	/* std::cout << "here" << std::endl; */
	if(matrix[i][j] > matrix[pi][pj] ){
		/* preSum[i][j] = preSum[i][j] +1; */
		preSum[i][j] = max(preSum[pi][pj] +1, preSum[i][j]);
		ans = max(ans, preSum[i][j]);
		/* std::cout << "Additona at " << matrix[i][j] << " "<< matrix[pi][pj]  << std::endl; */
	}

	std::cout << "after " << matrix[i][j] << " "<< matrix[pi][pj] << " " <<  preSum[i][j]<< std::endl;
	std::cout << "\n" << std::endl;
	if(visited[i][j] and matrix[i][j] <= matrix[pi][pj]){
		return;
	}

	visited[i][j] = true;

	/* std::cout << matrix[i][j] << std::endl; */

	dfs(i, j - 1, m, n,  matrix, i, j);
	dfs(i - 1, j, m, n,  matrix, i, j);
	dfs(i, j + 1, m, n,  matrix, i, j);
	dfs(i + 1, j, m, n,  matrix, i, j);
}
int longestIncreasingPath(vector<vector<int>>& matrix) {


	int m = matrix.size();
	int n = matrix[0].size();
	preSum[0][0]= 1;
   
	dfs(0, 0, m, n, matrix, 0, 0);	

	return ans;
}


int32_t main() {

	vector<vector<int>> matrix = {{0,1,2,3,4,5,6,7,8,9},{19,18,17,16,15,14,13,12,11,10},{20,21,22,23,24,25,26,27,28,29},{39,38,37,36,35,34,33,32,31,30},{40,41,42,43,44,45,46,47,48,49},{59,58,57,56,55,54,53,52,51,50},{60,61,62,63,64,65,66,67,68,69},{79,78,77,76,75,74,73,72,71,70},{80,81,82,83,84,85,86,87,88,89},{99,98,97,96,95,94,93,92,91,90},{100,101,102,103,104,105,106,107,108,109},{119,118,117,116,115,114,113,112,111,110},{120,121,122,123,124,125,126,127,128,129},{139,138,137,136,135,134,133,132,131,130},{0,0,0,0,0,0,0,0,0,0}};
	/* vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}}; */
	/* vector<vector<int>> matrix = {{1}}; */
	/* vector<vector<int>> matrix = {{9,9,4}, */
	/* 							  {6,6,8}, */
	/* 							  {2,1,1}}; */


	std::cout << longestIncreasingPath(matrix) << std::endl;
	return 0;
}

