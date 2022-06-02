#include <string>
#include <vector>
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") */
/* #pragma GCC optimize("unroll-loops") */
#include <bits/stdc++.h>  

using namespace std;

const int N = 1000;
/* vector<vector<string>> grid = { {"1","1","1","1","0"}, {"1","1","0","1","0"}, {"1","1","0","0","0"}, {"0","0","0","0","0"}}; */
/* vector<vector<string>> grid = { {"1","1","0","0","0"}, {"1","1","0","0","0"}, {"0","0","1","0","0"}, {"0","0","0","1","1"} }; */
vector<vector<string>> grid = { {"1","1","0","0","0"}, {"1","1","0","0","0"}, {"0","0","1","0","0"}, {"0","0","0","1","1"}};

bool visited[N][N];

void dfs(int i, int j, int m, int n){
	/* std::cout << vertex << std::endl; */
	if(i < 0 || i >= m || j < 0 || j >= n){
		return;
	}
	if(visited[i][j]){
		return;
	}
	visited[i][j] = true;
	if(grid[i][j] == "1"){
		dfs(i-1, j, m, n);
		dfs(i+1, j, m, n);
		dfs(i, j-1, m, n);
		dfs(i, j+1, m, n);	
	}
}


int32_t main(){
	
	int m = grid.size();
	int n = grid[0].size();

	int cnt = 0;
	std::cout << "m and n are "<<m<<" "<<n << std::endl;
	for(int i = 0; i< m; i++){
		for(int j = 0; j<n; j++){
			/* std::cout << "Here 1: " <<i<<" "<<j << std::endl; */
			if(visited[i][j]){
				continue;
			}
			if(grid[i][j] == "1"){

				dfs(i, j, m, n);
				cnt++;
			}
		}
	}

	std::cout << cnt << std::endl;
	return 0;
}


