#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

vector<vector<int>> allPerms;


void f(int &n, vector<int> &set, vector<int> &nums, vector<bool> &check){

	if(set.size() == n){
		allPerms.push_back(set);
		return;
	}

	for(int i = 0; i < n; i++){

		if(check[i]) continue;

		set.push_back(nums[i]);
		
		// Marking as used
		check[i] = true;

		f(n, set, nums, check);

		// Marking as unsed
		check[i] = false;

		set.pop_back();
	}
}

vector<vector<int>> permute(vector<int>& nums) {

	vector<bool> check(100);
	vector<int> empty;
	int n = nums.size();

	f(n, empty, nums, check);
	
	return allPerms;
}


int32_t main(){
	


	vector<int> nums = {1,2,3};
	for(auto v : permute(nums)){
		for(auto i : v){
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

