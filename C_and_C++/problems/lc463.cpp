#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int totalg = 0;

int dfs(int i, int j, int row, int col, int total, vector<vector<int>>& grid, vector<vector<bool>>& visited){
	/* std::cout <<i <<" " <<j << "  dfs total : "<<total << std::endl; */

	/* std::cout << "here1 " <<i <<" "<< j << " " << total << std::endl; */

	if(i < 0 || i >= row || j < 0 || j >= col){
		/* std::cout <<i <<" " <<j << "  dfs total : "<<total << std::endl; */
		/* std::cout << "R L " << row <<" "<<col << std::endl; */
		totalg += 1;
		return 1;
	}

	/* std::cout << "here2 " <<i <<" "<< j << std::endl; */
	/* std::cout << "here2 " <<i <<" "<< j << " " << total << std::endl; */
	if(visited[i][j]){
		/* std::cout <<"R V "<< std::endl; */
		return 0;
	}

	/* std::cout << "here3 " <<i <<" "<< j << std::endl; */
	/* std::cout << "here3 " <<i <<" "<< j << " " << total << std::endl; */
	if(grid[i][j] != 1){
		/* std::cout <<i <<" " <<j << "  dfs total : "<<total << std::endl; */
		/* std::cout << "R W " << std::endl; */
		totalg += 1;
		return 1;
	}
	visited[i][j] = true;
	/* std::cout << "here4 " <<i <<" "<< j << " " << total << std::endl; */
	total += dfs(i, j-1, row, col, total, grid, visited);
	/* std::cout << "1 dfs total : "<<total << std::endl; */
	total += dfs(i-1, j, row, col, total, grid, visited);
	/* std::cout << "2 dfs total : "<<total << std::endl; */
	total += dfs(i, j+1, row, col, total, grid, visited);
	/* std::cout <<i <<" " <<j << " 3 dfs total : "<<total << std::endl; */
	total += dfs(i+1, j, row, col, total, grid, visited);
	/* std::cout << "4 dfs total : "<<total << std::endl; */
	/* std::cout <<i <<" " <<j << " 3 dfs total : "<<total << std::endl; */
	
	/* std::cout << totalg << std::endl; */
	return totalg;
}

int islandPerimeter(vector<vector<int>>& grid) {
	
	const int N = 300;
	int total = 0;
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<bool>> visited(N, vector<bool> (N));

	for(int i= 0; i < row; i++){
		bool breakit = false;
		for(int j = 0; j< col; j++){
			if(grid[i][j] == 1){
				/* std::cout << i <<" " <<j << std::endl; */
				total = dfs(i, j, row, col, 0, grid, visited);
				breakit = true;
				break;
			}
		}
		if(breakit){
			break;
		}
	}
	/* total += dfs(0, 1, row, col, 0, grid, visited); */

	return total;
}

int32_t main(){
	vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0}, {1,1,0,0} };
	std::cout << islandPerimeter(grid) << std::endl;	

	return 0;
}

