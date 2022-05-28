#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int mid;

	std::cout << "Here1" << std::endl;
    sort(nums.begin(), nums.end());
    while(hi - lo > 1){
        mid = (hi+lo)/2;
		std::cout << "Here2" << std::endl;
        if(nums[mid] < target){
            lo = mid +1;
        }
        else if(nums[mid] > target){
            hi = mid -1;
        }
        else{
            ans.push_back(mid);
			hi = hi +1;
        }
    }
    return ans;
}

int32_t main(){

	vector<int> nums = {1,2,5,2,3};
	int target = 2;

	for(auto i : targetIndices(nums, target)){
		std::cout << i << std::endl;
	}

	return 0;
}

