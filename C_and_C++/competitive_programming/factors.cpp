#include <unordered_set>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

pair<unordered_set<int>, pair<int, int>> divisors(int n){
	unordered_set<int> set_of_divisors;
	
	int cnt = 0;
	int sum = 0;

	for(int i = 1; i * i <=n; ++i){
		if(n % i == 0){
			set_of_divisors.insert(i);
			set_of_divisors.insert(n/i);
			cnt++;
			sum += i;
			if(n / i != i){
				sum += n / i;
				cnt++;
			}
		}
	}
	return {set_of_divisors, {cnt, sum}};
}

int32_t main(){
	
	auto res = divisors(36);

	std::cout << "There are total "<< res.second.first << " divisors with sum "<< res.second.second << std::endl;

	for(auto i : res.first){
		std::cout << i << std::endl;
	}
	return 0;
}

