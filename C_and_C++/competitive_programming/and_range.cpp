#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int rangeBitwiseAnd(int left, int right) {
	int cnt = 0;
	while (left != right) {
		left >>= 1;
		right >>= 1;
		cnt++;
	}
	return left<<cnt;
}

int32_t main(){
	
	std::cout << rangeBitwiseAnd(5, 7) << std::endl;

	/* 
	 * 0 1 0 1  0 0 1 0   0 0 0 1 
	 * 0 1 1 1  0 0 1 1   0 0 0 1
	 *
	 *
	 *
	 *
	 * */


	return 0;
}

