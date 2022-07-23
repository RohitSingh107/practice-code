#include <cmath>
#include <cstdint>
#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5+10;
const int K = 105;

int dp[N];
int h[N];
int minimumCost(int n, int k){
	if(n == 0) return 0;

	if(dp[n] != -1) return dp[n];

	int cost = INT_MAX;
	/* cost = min(cost, minimumCost(n-1) + abs(h[n] - h[n-1])); */
	/* if(n != 1)cost = min(cost, minimumCost(n-2) + abs(h[n] - h[n-2])); */
	for(int i = 1; i<= k; i++){
		if(n - i >= 0){
			
			cost = min(cost, minimumCost(n-i, k) + abs(h[n] - h[n-i]));
		}
	}

	return dp[n] = cost;
}

int32_t main(){
	clock_t _t = clock();

	memset(dp, -1, sizeof(dp));

	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>h[i];
	}

	std::cout << minimumCost(n-1, k) << std::endl;


	

	cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
	return 0;
}

