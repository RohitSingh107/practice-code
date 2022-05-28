#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  



using namespace std;

int req(int x){
	if(x & 1){
		return x * (x+1)/2;
	}
	else{
		return (x * (x/2)) + (x/2);
	}
}

bool check(int x, int coins){
	/* cout<<"H1 "<<x<<" "<<coins<<endl; */
	if(req(x) <= coins){
		cout<<"H2 "<<req(x)<<" "<<coins<<endl;
		return true;
	}
	return false;
}

int arrangeCoins(int n) {
	int ans;
	int lo = 0;
	int hi = n;
	int mid;
	while (hi - lo > 1) {
		mid = (hi+lo)/2;
		if(check(mid, n)){
			lo = mid;
		}
		else {
			hi = mid-1;
		}
	}
	ans = lo;
	if(check(hi, n)){
		ans = hi;
	}
	/* cout<<lo<<" "<<mid<<" "<<hi<<endl; */
	return ans;
}

int32_t main(){
	
	/* cout<<check(8)<<endl; */
	std::cout << arrangeCoins(5) << std::endl;

	return 0;
}

