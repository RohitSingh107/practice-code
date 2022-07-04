#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool dfs(int x, int destination, vector<vector<int>>& graph, vector<bool>& visited){
	/* std::cout << "Entered " << x << std::endl; */
	if(x == destination){
		return true;
	}
	if(visited[x]){
		return false;
	}
	visited[x] = true;
	bool ans = false;
	for(int child : graph[x]){
		if(visited[child]) continue;
		/* std::cout << "heree " << x << std::endl; */
		ans = ans || dfs(child, destination, graph, visited);
	}
	return ans;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

	vector<vector<int>> graph(n);
	vector<bool> visited(n);

	for(auto v : edges){
		graph[v[0]].push_back(v[1]);
		graph[v[1]].push_back(v[0]);

	}
	/* std::cout << graph[0][1] << std::endl; */
	return dfs(source, destination, graph, visited);
}

int32_t main(){
	int n = 3;
	vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
	int source = 0;
	int destination = 2;

	std::cout << validPath(n, edges, source, destination) << std::endl;
	

	return 0;
}

