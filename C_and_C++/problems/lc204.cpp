#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

/* const int N = 1e7+5; */

int32_t main(){
	int n = 1500000;	
	vector<bool> isPrime(n, true);

	isPrime[0] = isPrime[1] = false;

	int cnt = 0;

	for(int i = 2; i< n; i++){
		if(isPrime[i]){
			if(i < n) cnt++;
			for(int j = 2 * i; j < n; j += i){
				isPrime[j] = false;
			}
		}
	}

	/* std::cout << isPrime[997] << std::endl; */
	std::cout << cnt << std::endl;

	return 0;
}

