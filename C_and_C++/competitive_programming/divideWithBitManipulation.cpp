#include <climits>
#include <cmath>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

#define ll long long int

int divide(int dividend, int divisor) {
	if(dividend == INT_MIN and divisor == -1){
		return INT_MAX;
	}
	
	bool isPositive = ((dividend >= 0) == (divisor >= 0));

	ll adivd = abs(dividend);
	ll adivs = abs(divisor);
	ll result = 0;
	while (adivd >= adivs) {
		ll divs = adivs;
		std::cout << divs << std::endl;
		ll quotient = 1;
		while (divs <= adivd) {
			/* std::cout << divs << std::endl; */
			if(divs == 0){
				/* std::cout << adivd <<" " << quotient << " " << result << std::endl; */
				return 0;
			}
			divs <<= 1;
			quotient <<= 1;
		}
		result += (quotient>>1);
		adivd -= (divs>>1);
	}
	return isPositive ? result : -1 * result;
}
int32_t main(){
	
	std::cout << divide(2147483647, 1) << std::endl;	


	return 0;
}

