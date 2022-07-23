#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;
const int N = 1e5+10;
int dp[N];


int fib(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;

	if(dp[n] != -1) return dp[n];

	return dp[n] = fib(n-1) + fib(n-2);
}

int32_t main(){
	clock_t _t = clock();

	memset(dp, -1, sizeof(dp));

	int n = 6;
	std::cout << fib(n) << std::endl;
	

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

