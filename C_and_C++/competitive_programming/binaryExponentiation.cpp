#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <chrono>

const int M = 1e9 + 7;

using namespace std;
using namespace std::chrono;

int binExpRec(int a, int b){
	if(b == 0) return 1;
	
	int res = binExpRec(a, b/2);
	
	if(b & 1){
		return (a * ((res * 1LL * res) % M)) % M;
	}
	else{
		return (res * 1LL * res) % M;
	}
}

int binExpIter(int a, int b){
	int ans = 1;
	while (b) {
		if(b&1){
			ans = (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b >>= 1;
	}
	return ans;
}

int32_t main(){
	auto start2 = high_resolution_clock::now();
	std::cout << binExpIter(2123123777, 1231231444) << std::endl;
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "Time taken by iteration " << duration2.count() << " microseconds" << endl;
	
	auto start = high_resolution_clock::now();
	std::cout << binExpRec(2123123777, 1231231444) << std::endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by recursion: " << duration.count() << " microseconds" << endl;

	return 0;
}

