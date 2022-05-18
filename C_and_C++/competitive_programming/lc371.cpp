#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int getSum(long long int a, long long int b) {
	
	if(a < 0){
		a = (1ll<<32) + a;
	}
	if(b < 0){
		/* b = ~(b) + 1; */
		b = (1ll<<32) + b;
	}
	while (b != 0) {
		long long int carry = a & b;
		std::cout << carry << std::endl;
		/* int sum = a ^ b; */
		a = a ^ b;
		b = carry<<1;
	}
    return a;    
}

int32_t main(){
	
	std::cout << getSum(-1, 1) << std::endl;	

	return 0;
}

