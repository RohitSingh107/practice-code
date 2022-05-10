#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


vector<int> findErrorNums(vector<int>& nums) {
	int n = nums.size();
	vector<int> ans;

	int tmp = 0;
	for(auto i : nums){
		tmp ^= i;
	}
	tmp = 4;
	int tmp2 = tmp;
	int i = 0;
	while(!(tmp & 1)){
		tmp2 =tmp2>>1;
		i++;
	}

	cout<<i<<endl;
	return ans;
}

int32_t main(){
	
	vector<int> nums= {1,2,2,4};

	findErrorNums(nums);

	return 0;
}

