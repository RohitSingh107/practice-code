#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 2e3+10;
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

	#ifndef ONLINE_JUDGE
	freopen("/home/rohits/mydata/code/C_and_C++/competitive_programming/inputf.in", "r", stdin);
	/* freopen("/home/rohits/mydata/code/C_and_C++/competitive_programming/outputf.in", "w", stdout); */
	#endif



	int n;
	cin>>n;

	vector<pair<int, int>> cities(n + 1);

	for(int i = 1; i <=n; i++){
		int x, y;
		cin>>x>>y;
		cities[i] = {x,y};
	}

	vector<int> costs(n + 1);
	for(int i = 1; i <= n; i++){
		std::cin >> costs[i];
	}
	vector<int> ks(n + 1);
	for(int i = 1; i <= n; i++){
		std::cin >> ks[i];
	}

	vector<pair<long long, pair<int, int>>> edges;

	for(int i = 1; i<= n; i++){
		edges.push_back({costs[i], {0,i}});
	}

	for(int i = 1; i<= n; i++){
		for(int j = i+1; j<=n; ++j){
			int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);

			long long cost = dist * 1LL * (ks[i] + ks[j]);
			edges.push_back({cost, {i, j}});
		}
	}
	

	sort(edges.begin(), edges.end());

	for(int i = 1; i <= n; ++i) make(i);

	long long totalCost = 0;
	vector<int> power_stations;
	vector<pair<int, int>> connections;
	for(auto &edge : edges){
		int w = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if(find(u) == find(v)) continue;
		doUnion(u, v);
		totalCost += w;

		if(u == 0 || v == 0){
			power_stations.push_back(max(u,v));
		}
		else{
			connections.push_back({ u, v });
		}

		
	}

	std::cout << totalCost << std::endl;
	std::cout << power_stations.size() << std::endl;
	for(int station : power_stations){
		std::cout << station  << " ";
	}
	std::cout << std::endl;

	std::cout << connections.size() << std::endl;

	for(auto &connection : connections){
		std::cout << connection.first << " " << connection.second << std::endl;
	}

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

