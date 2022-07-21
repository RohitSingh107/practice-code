#include <climits>
#include <set>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5;
const int I = 1e9+10;

vector<vector<pair<int, int>>> graph(N);
vector<bool> visited(N);



void dijkstra(int source){
	vector<int> vis(N, 0);
	vector<int> dist(N, I);

	set<pair<int, int>> pq;	

	pq.insert({ 0, source });
	dist[source] = 0;

	int mx = INT_MIN;

	while (pq.size() > 0) {
		pair<int, int> node = *pq.begin();

		int v = node.second;
		int dst = node.first;

		pq.erase(pq.begin());

		if(visited[v]) continue;
		visited[v] = 1;


		for(auto child : graph[v]){

			int child_v = child.first;
			int w = child.second;

			if(dist[v] + w < dist[child_v]){
				dist[child_v] = dist[v] + w;

				pq.insert({ dist[child_v], child_v });

				mx = max(mx, dist[child_v]);
			}
		}
	}

	std::cout << "maximux distance is " << mx << std::endl;
}


int32_t main(){
	int n = 4; // Number of Nodes
	int vexEd[3][3] = { {2,1,1 } , {2,3,1} , {3,4,1}};

	for (int i = 0; i < n - 1; i++) {
		int v1 = vexEd[i][0];
		int v2 = vexEd[i][1];
		int w = vexEd[i][2];

		graph[v1].push_back({ v2, w });
	}



	

	dijkstra(2);





	

	return 0;
}

