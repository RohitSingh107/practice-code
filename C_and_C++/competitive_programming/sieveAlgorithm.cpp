#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e7+10;

vector<bool> isPrime(N,1);

int32_t main(){
	
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i<N; ++i){
		if(isPrime[i]){

			for(int j = 2 * i; j < N; j += i){
				isPrime[j] = false;
			}
		}
	}
	for(int i = 1; i < 1e7+9; ++i){
		if(isPrime[i]){
			std::cout << i << " is Prime." << std::endl;
		}
		else{
			std::cout << i << " is not Prime." << std::endl;
		}
	}

	return 0;
}

