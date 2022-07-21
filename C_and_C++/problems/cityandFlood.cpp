#include <algorithm>
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
		/* sizeOfTree[a] += sizeOfTree[b]; */
	}

}

int32_t main(){
	clock_t _t = clock();


	int n, k;
	cin>>n>>k;

	for(int i = 1; i <= n; ++i){
		make(i);
	}
	while (k--) {
		int u, v;
		cin>>u>>v;
		doUnion(u, v);
	}

	int connected_ct = 0;
	for(int i = 1; i<=n; ++i){
		if(find(i) == i) connected_ct++;
	}

	std::cout << connected_ct << std::endl;

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

