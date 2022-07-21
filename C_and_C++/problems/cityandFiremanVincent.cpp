#include <algorithm>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5+10;
const int M = 1e9+7;
int parent[N];
int sizeOfTree[N];
int risk[N];
int mins[N];


void make(int v, int rsk){
	parent[v] = v;
	sizeOfTree[v] = 1;
	mins[v] = rsk;
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

		int mn = min(mins[a], mins[b]);
		mins[a] = mn;
		mins[b] = mn;
		
		sizeOfTree[a] += sizeOfTree[b];
	}

}

int32_t main(){
	clock_t _t = clock();


	int n;
	cin>>n;

	for(int i = 1; i <= n; ++i){
		cin>>risk[i];
	}
	for(int i = 1; i <= n; ++i){
		make(i, risk[i]);
	}
	int k;
	cin>>k;

	while (k--) {
		int u, v;
		cin>>u>>v;
		doUnion(u, v);
	}

	vector<int> roots;

	int connected_ct = 0;
	for(int i = 1; i<=n; ++i){
		if(find(i) == i) {
			connected_ct++;
			roots.push_back(i);
			/* std::cout << "Minimux is " <<  mins[i] << " with root " << i << std::endl; */
		} 
	}

	long long int ans = 1;
	for(int root : roots){
		int node_c = 0;
		for(int i = 1; i <= n; i++){
			if(risk[i] == mins[root]){
				/* std::cout <<"i is " << i << " mins[i] is " << mins[i] << " mins root is " << mins[root] << std::endl; */
				if(find(i) == root){
					node_c = (node_c + 1) % M;
					/* std::cout << "node c is " << node_c << " incrementing for " << i << std::endl; */
				}
			}
		}
		ans = (ans * node_c) % M;

		/* std::cout << "\n\n\n Set finished \n\n\n" << std::endl; */
	}


	std::cout << ans << std::endl; 

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

