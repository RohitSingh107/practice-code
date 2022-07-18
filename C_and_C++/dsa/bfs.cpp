#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5;

vector<vector<int>> graph(N);
vector<bool> visited(N);

int level[N];

void bfs(int source){
	
	queue<int> q;

	q.push(source);

	while (!q.empty()) {
		int parent = q.front();
		visited[parent] = true;
		q.pop();
		std::cout << parent <<" ";

		for(int child : graph[parent]){
			if(visited[child]) continue;
			q.push(child);
			level[child] = level[parent] + 1;
			visited[child] = true; // Very Vey Very Important
		}
	}
	std::cout << std::endl;
}

int32_t main(){
	int n = 13; // Number of Nodes
	int vexEd[12][12] = { {1,2} , {1,3} , {1 ,13}, {2,5}, {3,4}, {5,6}, {5,7}, {5,8}, {8,12}, {4,9}, {4,10}, {10,11} };

	for (int i = 0; i < n - 1; i++) {
		int v1 = vexEd[i][0];
		int v2 = vexEd[i][1];

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	bfs(1);

	std::cout << "Printing level" << std::endl;

	for (int i = 1; i <= n; i++) {
		std::cout << i << ": " << level[i] << std::endl;
	}

	

	return 0;
}

