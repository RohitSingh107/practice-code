#include <bits/types/clock_t.h>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N= 505;

int visited[N][N];
int level[N][N];

bool isValid(int x, int y, int cX, int cY){
	return x > 0 and y > 0 and x <= cX and y <= cY;
}

vector<pair<int,int>> movements = {
	{-1, 2}, {1, 2},
	{2, -1}, {2, 1},
	{1, -2}, {-1, -2},
	{-2, -1}, {-2, 1}
};

int bfs(int sourceX, int sourceY, int destX, int destY, int cX, int cY){

	queue<pair<int, int>> q;

	q.push({ sourceX, sourceY });
	visited[sourceX][sourceY] = 1;

	while (!q.empty()) {
		auto parent = q.front();
		int parentX = parent.first;
		int parentY = parent.second;

		visited[parentX][parentY] = 1;

		q.pop();

		for(auto p : movements){
			/* pair<int,int> child = {parentX + p.first, parentY + p.second}; */
			int childx = parentX + p.first;
			int childy = parentY + p.second;
			
			if(!isValid(childx, childy, cX, cY)) continue;
			if(visited[childx][childy]) continue;

			q.push({ childx, childy });
			level[childx][childy] = level[parentX][parentY] + 1;
			visited[childx][childy] = 1; // Very Vey Very Important
		}

		if(level[destX][destY] != 0){
			break;
		}
	}

	return level[destX][destY];
}

int knight(int A, int B, int C, int D, int E, int F) {
	return bfs(C, D, E, F, A, B);
}

int32_t main(){
	clock_t z = clock();

	/* std::cout << knight(8, 8, 1, 1, 8, 8) << std::endl; */
	/* std::cout << knight(7, 13, 2, 8, 3, 4) << std::endl; */
	
    std::cout << knight(384, 387, 106, 134, 210, 35) << std::endl;
	cerr << "Run Time: " << (double)(clock() - z) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

