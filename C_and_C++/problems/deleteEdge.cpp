#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


void dfs(int vertex, int parent, vector<vector<int>> &graph, vector<int> &subTree_sum, vector<int> weights){

	subTree_sum[vertex] += weights[vertex - 1];

	for(int child : graph[vertex]){
		if(child == parent) continue;

		dfs(child, vertex, graph, subTree_sum, weights); 
		subTree_sum[vertex] += subTree_sum[child];
	}
}

int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
	int N = 1e5+10;
	vector<vector<int>> graph(N);
	vector<int> subTree_sum(N, 0);

	for(auto v : B){
		graph[v[0]].push_back(v[1]);
		graph[v[1]].push_back(v[0]);
	}

	dfs(1, -1, graph, subTree_sum, A);

	int ans = -1;
	for(int i = 2; i<= A.size(); i++){
		
		int subTree1 = subTree_sum[i];
		int subTee2 = subTree_sum[1] - subTree_sum[i];

		ans = max(ans, subTee2 * subTree1);
	}
	/* std::cout << "1 is " << subTree_sum[1] <<" 4 is "<< subTree_sum[4] << std::endl; */
	return ans;
}
int32_t main(){

/* 	vector<int> A = {10, 5, 12, 6}; */
/* 	vector<vector<int>> B = {{1, 2}, {1, 4}, {4, 3}}; */
	
	vector<int> A = {11, 12};
	vector<vector<int>> B = {{1, 2}};
	
	std::cout << deleteEdge(A, B) << std::endl;

	

	return 0;
}

