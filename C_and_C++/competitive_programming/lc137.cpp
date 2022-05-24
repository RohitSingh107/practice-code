#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;
int singleNumber(vector<int>& nums) {
	int ones = 0;
	int twos = 0;
	for(auto i : nums){
		ones = (ones ^ i) & (~twos);
		twos = (twos ^ i) & (~ones);
	}
	return ones;
}
int32_t main(){

	vector<int> nums = {0,1,0,1,0,1,99};
	
	std::cout << singleNumber(nums) << std::endl;
	

	return 0;
}

