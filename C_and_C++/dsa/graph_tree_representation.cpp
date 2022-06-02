#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e3+10;

int graph1[N][N];

vector<pair<int, int>> graph2[N]; // N vectors;

int32_t main(){

	// Adjency Matrix
	int n = 6, m = 9;
	int vexEd[9][9] = { {1,3, 4} , {1,5, 3} , {3,5, 2}, {3,4, 7}, {3,6, 8}, {3,2, 9}, {2,6, 1}, {4,6, 2}, {5,6, 3} };

	for (int i = 0; i < m; i++) {
		int v1 = vexEd[i][0];
		int v2 = vexEd[i][1];
		int wgt =vexEd[i][2];

		graph1[v1][v2] = 1;
		graph1[v2][v1] = 1;
		// O(N^2) - space complexity
		
		graph2[v1].push_back({v2, wgt});
		graph2[v2].push_back({v1, wgt});
		// O(V+E) - space complexity
	}

	return 0;
}

