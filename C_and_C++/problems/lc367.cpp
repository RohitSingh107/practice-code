#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool isPerfectSquare(int num) {

	int lo = 1;
	int hi = num;
	int mid;
	while (hi-lo >1) {
		mid = (hi+lo)/2;
		/* cout<<"H1 "<<mid<<endl; */
		if(mid * mid == num){
			return true;
		}
		else if (mid * mid < num) {
			lo = mid + 1;
		}
		else {
			hi = mid-1;
		}
	}

	return lo * lo == num || hi * hi == num;
}

int32_t main(){
	
	cout<<isPerfectSquare(144);	

	return 0;
}

