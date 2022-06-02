#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited){
	if(i < 0 || i >= n || j<0 || j>= m){
		return;
	}
	if(visited[i][j]){
		return;
	}

	visited[i][j] = true;
	if(grid[i][j] == 1){
		dfs(i-1, j-1, n, m, grid, visited);
		dfs(i-1, j, n, m, grid, visited);
		dfs(i-1, j+1, n, m, grid, visited);
		dfs(i, j-1, n, m, grid, visited);
		dfs(i, j+1, n, m, grid, visited);
		dfs(i+1, j-1, n, m, grid, visited);
		dfs(i+1, j, n, m, grid, visited);
		dfs(i+1, j+1, n, m, grid, visited);
	}
}

int numIslands(vector<vector<int>>& grid) {
		const int N = 1000;
        int n = grid.size();
		int m = grid[0].size();
		std::cout << n <<" "<< m << std::endl;;
		vector<vector<bool>> visited(N, vector<bool> (N, false));
		int cnt = 0;

		for(int i = 0; i< n; i++){
			for(int j = 0; j <m; j++){
			
				if(visited[i][j]){
					continue;
				}
				if(grid[i][j] == 1){
					dfs(i, j, n, m, grid, visited);
					cnt++;
				}
			}
		}

		return cnt;
}

int32_t main(){
	
	vector<vector<int>> grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};

	std::cout << numIslands(grid) << std::endl;

	return 0;
}

