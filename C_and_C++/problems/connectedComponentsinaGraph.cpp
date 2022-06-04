#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


void dfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited){
	if(visited[vertex]){
		return;
	}
	visited[vertex] = true;
	for(int child : graph[vertex]){
		if(visited[child]) continue;
		dfs(child, graph, visited);
	}
}

int32_t main(){

	int n, e;
	cin>>n>>e;
	int N= 1000;
	vector<vector<int>> graph(N);
	vector<bool> visited(N);
	for(int i =0; i<e; i++){
		int v1, v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(visited[i]) continue;

		dfs(i, graph, visited);
		cnt++;
	}
	std::cout << cnt << std::endl;
	

	return 0;
}

