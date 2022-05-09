#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool check(vector<int> &C, int mid){
	
}

int paint(int A, int B, vector<int> &C) {
	int n = C.size();
	int lo = 0;
	int hi = n-1;
	int mid;
	while (hi - lo > 1) {
		mid = (lo + hi)/2;
		if(check(C, mid)){
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	if(check(C, mid)){
		return mid;
	}
	else{
		return mid;
	}
}

int32_t main(){
	
	int A = 2;
	int B = 5;

	vector<int> C = {1,10};

	cout<<paint(A, B, C)<<endl;
	
	return 0;
}

