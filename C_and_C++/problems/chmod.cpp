#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


int game(int l, int r, int m){
	int ans = 1;
	for(int i = l; i<= r; i++){
		ans = (ans * 1LL * i) % m;
	}
	return ans;
}

int32_t main(){
	
	int n;
	cin>>n;

	vector<int> v(n);
	for(auto &i : v) cin>>i;
	
	int t;
	cin>>t;
	
	while(t--){
		int l, r, m;
		cin>>l>>r>>m;
		std::cout << game(l, r, m) << std::endl;
	}

	return 0;
}

