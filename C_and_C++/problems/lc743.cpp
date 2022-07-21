#include <climits>
#include <set>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int I = 1e9+10;





    // const int N = 1e5;

    // vector<vector<pair<int, int>>> graph(N);
    // vector<bool> visited(N);



int dijkstra(int source, int n, vector<vector<pair<int, int>>> &graph){
    const int N = 1e5;
    vector<int> visited(N, 0);
    vector<int> dist(N, I);


    set<pair<int, int>> pq;	
    pq.insert({ 0, source });
    dist[source] = 0;

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
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
		if(dist[i] == I){
			return -1;
		}
        ans = max(ans, dist[i]); 
    }
    return ans;
}
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
    const int N = 1e5;
    vector<vector<pair<int, int>>> graph(N);
    for (auto vec : times) {
        int v1 = vec[0];
        int v2 = vec[1];
        int w =  vec[2];
        graph[v1].push_back({ v2, w });
    }
    return dijkstra(k, n, graph);
}

 







int32_t main(){


	int n = 2;
	int k = 2;
	vector<vector<int>> times = {{1,2,1},{2,1,3}};
	

	std::cout << networkDelayTime(times, n, k) << std::endl;





	

	return 0;
}

