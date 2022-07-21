#include <future>
#include <set>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5+10;

int parent[N];
int sizes[N];

multiset<int> groups;

void make(int v){
	parent[v] = v;
	sizes[v] = 1;
	groups.insert(1);
}

int find(int v){
	if(parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void merge(int a, int b){

	groups.erase(groups.find(sizes[a]));
	groups.erase(groups.find(sizes[b]));
	groups.insert(sizes[a] + sizes[b]);

}

void doUnion(int a, int b){
	a = find(a);
	b = find(b);

	if(a != b){
		if(sizes[a] < sizes[b]) swap(a, b);
		parent[b] = a;

		merge(a, b);

		sizes[a] += sizes[b];
	}
}

int32_t main(){
	clock_t _t = clock();


	int n, q;
	cin>>n>>q;

	for(int i = 1; i <= n; i++){
		make(i);
	}

	while (q--) {
		int A, B;
		cin>>A>>B;
		doUnion(A, B);	

		int mn = *(groups.begin());
		int mx = *(--groups.end());

		std::cout << mx - mn << std::endl;
	}

	

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

