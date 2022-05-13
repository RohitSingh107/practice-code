#include <cstdint>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int hammingWeight(uint32_t n) {
	int cnt = 0;
	for(uint32_t i = 0; i<= 31; i++){
		if((n>>i) & 1){
			cnt++;
		}
	}
	return cnt;
}
int32_t main(){
	
	

	return 0;
}

