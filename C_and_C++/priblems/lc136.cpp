#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int singleNumber(vector<int>& nums) {
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		ans ^= nums[i];
	}	
	return ans;
}
int32_t main(){
	vector<int> nums = {4,1,2,1,2};
	std::cout << singleNumber(nums) << std::endl;
	return 0;
}

