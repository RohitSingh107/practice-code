#include <algorithm>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5+10;
int parent[N];
int sizeOfTree[N];

void make(int v){
	parent[v] = v;
	sizeOfTree[v] = 1;
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]); // Path comression
}

void doUnion(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		// Union by sizeOfTree
		if(sizeOfTree[a] < sizeOfTree[b]) swap(a,b);
		parent[b] = a;
		sizeOfTree[a] += sizeOfTree[b];
	}

}

int32_t main(){
	clock_t _t = clock();

	int n = 6, m = 9;

	vector<vector<int>> edgesWithWeight = {
		{5,4,9},
		{1,4,1},
		{5,1,4},
		{4,3,5},
		{4,2,3},
		{1,2,2},
		{3,2,3},
		{3,6,8},
		{2,6,7}
	};


	vector<pair<int, pair<int, int>>> edges;
	for(auto &edge : edgesWithWeight){

		edges.push_back({edge[2], {edge[0],edge[1]}});
		
	}

	sort(edges.begin(), edges.end());

	for(int i = 1; i <= n; ++i) make(i);

	int totalCost = 0;
	for(auto &edge : edges){
		int w = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if(find(u) == find(v)) continue;
		doUnion(u, v);
		totalCost += w;

		std::cout << u << " " << v << std::endl;
		
	}

	std::cout << "Total cost: " << totalCost << std::endl;

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

