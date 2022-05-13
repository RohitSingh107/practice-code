#include <cmath>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

string toHex(long long int num) {
	if(num == 0){
		return "0";
	}
	else if(num < 0){
		std::cout << "H1 " << std::endl;
		num = num + pow(2, 32);
	}

	std::cout << "H2 "<< num << std::endl;
	char mp[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	string ans = "";
	while (num != 0) {
		ans = mp[num & 15] + ans;
		num = num >> 4;
	}
	return ans;
}

int32_t main(){
	
	std::cout << toHex(-1) << std::endl;
	return 0;
}

