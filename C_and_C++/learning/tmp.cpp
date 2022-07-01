#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

template<typename t>
void print(t s, t e){
	for(; s < e; s++){
		std::cout << *s << std::endl;
	}
}


int32_t main(){

	vector<int> v = {1, 2, 3, 4, 5};

	int i = 1;

	print(v.begin() + i, v.end());

	return 0;
}



