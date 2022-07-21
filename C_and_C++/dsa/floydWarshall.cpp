#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 510;
const int I = 1e9+10;
int d[N][N];

int32_t main(){
	clock_t _t = clock();
	int n = 6, e = 9;

	vector<vector<int>> vEw = {
		{1,2,1},
		{1,3,5},
		{2,3,2},
		{3,5,2},
		{2,5,1},
		{2,4,2},
		{4,5,3},
		{4,6,1},
		{5,6,2},
	};


	for(int i = 0; i< N; i++){
		for(int j = 0; j < N; j++){
			if(i == j) d[i][j] = 0;
			else d[i][j] = I;
		}
	}

	for(auto edges : vEw){
		d[edges[0]][edges[1]] = edges[2];
	}

	for(int k = 1; k <= n; ++k){ // included Nodes
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; j++){
				if(d[i][k] == I || d[k][j] == I) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(d[i][j] == I){
				std::cout << "I ";
			}
			else{
				std::cout << d[i][j] << " ";
			}
		}
		std::cout << std::endl;
		
	}

	

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

