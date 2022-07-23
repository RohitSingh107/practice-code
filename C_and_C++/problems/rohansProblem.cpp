#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5+10;

int parent[N];
int sizes[N];

multiset<pair<int,int>> groups;

void make(int v){
	parent[v] = v;
	sizes[v] = 1;
	groups.insert({1,v});
}

int find(int v){
	if(parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void merge(int a, int b){

	groups.erase(groups.find({sizes[a], a}));
	groups.erase(groups.find({sizes[b], b}));
	groups.insert({ sizes[a] + sizes[b],  a});

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


	int n;
	string s;
	cin>>n;
	cin>>s;

	for(int i = 1; i<= n; i++){
		make(i);
	}

	for(int i = 1; i <= n; i++){

		int n1 = i - 2;
		int n2 = i - 1;
		int n3 = i + 1;
		int n4 = i + 2;


		if(n1 > 0 and n1 <= n and s[i-1] == 'c'){
			doUnion(i, n1);
		}
		if(n2 > 0 and n2 <= n and s[i-1] == 'c'){
			doUnion(i, n2);
		}
		if(n3 > 0 and n3 <= n and s[i-1] == 'c'){

			doUnion(i, n3);
		}
		if(n4 > 0 and n4 <= n and s[i-1] == 'c'){
			doUnion(i, n4);
		}

	}



	pair<int,int> biggestSet = *(--groups.end());

	string ans = "";
	for(int i = 1; i<= n; i++){
		if(find(i) == biggestSet.second){
			ans.append("I");
		} else{
			ans.append("U");
		}
	}

	std::cout << ans << std::endl;


	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

