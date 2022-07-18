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


bool isValid(int x, int y, int cX, int cY){
	return x > 0 and y > 0 and x <= cX and y <= cY;
}

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){

	int level[1001][1001];
	int visited[1001][1001];

	int sourceX = KnightPos[0];
	int sourceY = KnightPos[1];

	int destX = TargetPos[0];
	int destY = TargetPos[1];

	int pxd[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
	int pyd[8] = {2, 2, -1, 1, -2, -2, -1, 1};

	for(int i = 0 ; i< 1001; i++){
		for(int j = 0; j < 1001; j++){
			visited[i][j] = 0;
			level[i][j] = 0;
		}
	}

	if(sourceX == destX and sourceY == destY){
		std::cout << "here 0" << std::endl;
		return 0;
	}

	visited[sourceX][sourceY] = 1;
	queue<pair<int, int>> q;

	q.push({sourceX, sourceY});

	while (!q.empty()) {
		auto parent = q.front();
		
		int parentX = parent.first;
		int parentY = parent.second;

		visited[parentX][parentY] = 1;
		q.pop();

		for(int i = 0; i< 8; i++){
			int childX = pxd[i] + parentX;
			int childY = pyd[i] + parentY;

			if(isValid(childX, childY, N, N) and visited[childX][childY] == 0){

				level[childX][childY] = level[parentX][parentY] + 1;
				if(childX == destX and childY == destY){
					std::cout << "here" << std::endl;
					return level[childX][childY];
				}
				q.push({ childX, childY });
			}
			
		}
	}

	return -1;
}

int32_t main(){
	clock_t z = clock();
	
	vector<int> KnightPos = {5, 3};
	vector<int> TargetPos = {5,5};

	std::cout << minStepToReachTarget(KnightPos, TargetPos, 5) << std::endl;

	
	cerr << "Run Time: " << (double)(clock() - z) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

