#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int n = 4;
/* int n = 4; */
long long m = 7;

long long trees[n] = {20, 15, 10, 17};

bool isSuff(int mid){
	long long wood = 0;
	for(int i = 0; i<n; i++){
		if(trees[i] >= mid){
			wood += (trees[i] - mid);
		}
	}
	return wood >= m;
}

int32_t main(){

	long long lo = 0, hi = 1e9, mid;

	while (hi- lo > 1) {
		mid = (hi+lo)/2;
		if(isSuff(mid)){
			lo = mid;
		}
		else {
			hi = mid-1;
		}
	}
	
	if(isSuff(hi)){
		cout<<hi<<endl;
	}
	else {
		cout<<lo<<endl;
	}

	return 0;
}

