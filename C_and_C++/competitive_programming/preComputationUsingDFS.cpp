#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5;


int subTree[N];

int evenCount[N];

vector<vector<int>> graph(N);

void dfs(int vertex, int parent){

	subTree[vertex] += vertex;
	if(vertex % 2 == 0) evenCount[vertex]++;
 
	for(int child : graph[vertex]){
		if(child == parent) continue;
		
		dfs(child, vertex);

		subTree[vertex] += subTree[child];
		evenCount[vertex] += evenCount[child];

	}
}

int32_t main(){
	int n = 13;
	int vexEd[12][2] = { {1,2} , {1,3} , {1 ,13}, {2,5}, {3,4}, {5,6}, {5,7}, {5,8}, {8,12}, {4,9}, {4,10}, {10,11} };

	for (int i = 0; i < n-1; i++) {
		int v1 = vexEd[i][0];
		int v2 = vexEd[i][1];

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(1, 0);

	for(int i =1; i <=n; i++){
		std::cout << subTree[i] << " " << evenCount[i] << std::endl;
	}

	return 0;
}

