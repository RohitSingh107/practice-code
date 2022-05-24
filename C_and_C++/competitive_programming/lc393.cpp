/* 393. UTF-8 Validation */

#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool validUtf8(vector<int>& data) {
	int rb = 0;
	for(auto i : data){
		if(rb == 0){
			/* std::cout << "Here2" << std::endl; */
			if((i >> 7) == 0b0){
				rb = 0;
			}
			else if((i >> 5) == 0b110){
				rb = 1;
			}
			else if((i >> 4) == 0b1110){
				rb = 2;
			}
			else if((i >> 3) == 0b11110){
				rb = 3;
			}
			else{
				return false;
			}
		}
		else{
			/* std::cout << "Here" << std::endl; */
			if((i >> 6) == 0b10){
				rb--;
			}
			else{
				return false;
			}
		}
	}
	/* std::cout << rb << std::endl; */
	return rb == 0;
}


int32_t main(){
	
	vector<int> data = {255};	
	std::cout << validUtf8(data) << std::endl;
	std::cout << (255>>7) << std::endl;

	return 0;
}

