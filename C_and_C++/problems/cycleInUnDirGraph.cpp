#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;



bool dfs(int vertex, int parent, vector<vector<int>>& graph, vector<bool>& visited){
	visited[vertex] = true;
	bool res = false;
	for(int child : graph[vertex]){
		if(visited[child] && child == parent) continue;	
		if(visited[child]) return true;
		res |= dfs(child, vertex, graph, visited);
	}
	return res;
}

int solve(int A, vector<vector<int> > &B) {

	int N = 3e5+5; 
	vector<vector<int>> graph(N);
	vector<bool> visited(N);
	
	int m = B.size();
	for(int i = 0; i<m; i++){
		int v1 = B[i][0];
		int v2 = B[i][1];
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	
	bool res = false;
	for(int i = 1; i<= A; i++){
		if(visited[i]) continue;
		if(dfs(i, 0, graph, visited)){
			res = true;
			break;
		}	
	}


	return res;
}
int32_t main(){
	int A = 5;

    vector<vector<int>> B = {{1, 2}, {1, 3}, {2, 3}, {1, 4}, {4, 5}};
	std::cout << solve(A, B) << std::endl;
	

	return 0;
}

