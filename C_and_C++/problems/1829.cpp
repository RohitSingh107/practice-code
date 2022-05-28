#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
	int n = nums.size();
	vector<int> pf(n);
	pf[0] = nums[0];
	for(int i = 1; i < n; i++){
		pf[i] = pf[i-1] ^ nums[i];
	}
	/* std::cout << pf[n-1] << std::endl; */
	/* std::cout << "Sixe is " << n << std::endl; */	
	/* maximumBit = 2; */
	vector<int> ans(n);
	for(int i = n -1; i >= 0; i--){
		/* std::cout << ((( (1<<maximumBit) -1) & pf[i])) <<" "<< pf[i] << std::endl; */
		int x = (((1<<(maximumBit)) -1) & pf[i]);
		/* std::cout << x << std::endl; */
		ans[n-1 - i] = ((~(x)) & (1<<maximumBit) -1 );
	}
	return ans;
}

int32_t main(){
	
	vector<int> nums = {0,1,2,2,5,7};

	int maximumBit = 3;
	/* getMaximumXor(nums, maximumBit); */
	for(auto i : getMaximumXor(nums, maximumBit)){
		std::cout << i << std::endl;
	}

	return 0;
}

