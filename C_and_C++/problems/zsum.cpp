#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

const int M = 1e9+7;

using namespace std;

int f(int n, int k){
	int Sn = 0;
	int Pn = 0;
	for(int i = 1; i<= n; i++){
		Sn = Sn + fs(i, k);
		Pn = Pn + fp(i);
	}
	return expression;
}


int32_t main(){
	
	

	return 0;
}

