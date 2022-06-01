#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


const int M = 1e9 + 7;

using namespace std;

int binExp(int a, int b, int m){
	int ans = 1;
	while (b) {
		if(b&1){
			ans = (ans * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	}
	return ans;
}

int32_t main(){
	
	std::cout << binExp(2, M-2, M) << std::endl;

	return 0;
}

