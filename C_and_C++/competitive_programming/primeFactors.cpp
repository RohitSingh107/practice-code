#include <unordered_map>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e7+10;

vector<bool> isPrime(N,1);
vector<int> lowestPrime(N,0), highestPrime(N,0);

vector<int> divisors[N];
int sum[N];

int32_t main(){
	
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i<N; ++i){
		if(isPrime[i]){
			
			lowestPrime[i] = highestPrime[i] = i;

			for(int j = 2 * i; j < N; j += i){
				
				isPrime[j] = false;
				
				highestPrime[j] = i;
				if(lowestPrime[j] == 0){
					lowestPrime[j] = i;
				}

			}
		}
	}

	int num = 24;
	unordered_map<int, int> prime_factors;
	while (num > 1 ) {
		int prime_factor = highestPrime[num];
		while (num % prime_factor == 0) {
			num /= prime_factor;
			prime_factors[prime_factor]++;
		}
	}
	
	for(auto factor : prime_factors){
		std::cout << factor.first << " " << factor.second << std::endl;
	}

	// Divisors
	for(int i = 2; i< N; ++i){
		for(int j = i; j< N; j+=i){
			divisors[j].push_back(i);
			sum[j] += i;
		}
	}

	std::cout << "Divisors" << std::endl;
	for(int i = 1; i < 10; ++i){
		for(int div : divisors[i]){
			std::cout << div << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

