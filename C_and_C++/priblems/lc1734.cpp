#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

vector<int> decode(vector<int>& encoded) {
	int es = encoded.size();
	int n = 1 + es;
	vector<int> ans(n);
	int x = 0;
	for(int i = 1; i<= n; i++){
		x ^= i;
	}
	for(int i = 1; i<es; i++){
		if(i&1){
			x ^= encoded[i];
		}
	}
	/* std::cout << x << std::endl; */
	ans[0] = x;
	for(int i = 1; i<n; i++){
		ans[i] = encoded[i-1] ^ ans[i-1];
	}

	return ans;
}

int32_t main(){
	
	vector<int> encoded = {6,5,4,6};
	for(auto i : decode(encoded)){
		std::cout << i << std::endl;
	}

	return 0;
}

