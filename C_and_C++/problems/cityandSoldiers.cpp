#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5+10;
int leader[N];

void make(int v){
	leader[v] = v;
}

int findLeader(int v){

	if(v == leader[v]) return v;
	return leader[v] = findLeader(leader[v]); // Path comression
	/* int tmp = findLeader(leader[v]); */
	/* leader[v] = tmp; */
	/* return tmp; */
}

void doUnion(int a, int b){
	
	a = findLeader(a);
	b = findLeader(b);
	if(a != b){
		leader[a] = b;
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
		int tq;
		cin>>tq;
		if(tq == 1){
			int a, b;
			cin>>a>>b;
			doUnion(a, b);
		}
		else if(tq == 2){
			int a;
			cin>>a;
			leader[findLeader(a)] = a;
			leader[a] = a;
		}
		else{
			int a;
			cin>>a;
			std::cout << findLeader(a) << std::endl;
		}
	}


	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

