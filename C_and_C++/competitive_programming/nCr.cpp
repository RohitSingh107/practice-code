#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7;
const int N = 1e6+10;
int factorial[N];

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

int nCr(int n, int r){

	int ans = factorial[n];
	int den = (factorial[r] * 1LL * factorial[n - r]) % M;
	// Finding Modular Multiplicative Inverse
	ans = (ans * 1LL * binExp(den, M - 2, M)) % M;

	return ans;
}

int nPr(int n, int r){

	int ans = factorial[n];
	int den = factorial[n - r];
	// Finding Modular Multiplicative Inverse
	ans = (ans * 1LL * binExp(den, M - 2, M)) % M;

	return ans;
}


int32_t main(){
	
	factorial[0] = 1;
	for(int i = 1; i < N; ++i){
		factorial[i] = (factorial[i-1] * 1LL * i) % M;
	}

	std::cout << nCr(86, 83) << std::endl;
	std::cout << nPr(7, 2) << std::endl;

	return 0;
}

