#include <climits>
#include <cmath>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


int ans = INT_MAX;
int cm = INT_MAX;

void f(int &n, vector<int> &set, vector<int> &nums, vector<bool> &check, int target){

	if(set.size() == 3){
		int tmp = 0;
		for(int i : set){
			tmp += i;
		}
		/* std::cout << tmp << std::endl; */
		int c = abs(tmp - target);
		if(c < cm){
			ans = tmp;
		}
		cm = min(cm, c);
		
		/* std::cout << cm << std::endl; */

		return;
	}

	for(int i = 0; i < n; i++){

		if(check[i]) continue;

		set.push_back(nums[i]);
		
		// Marking as used
		check[i] = true;

		f(n, set, nums, check, target);

		// Marking as unsed
		check[i] = false;

		set.pop_back();
	}
}

int permute(vector<int>& nums, int target) {

	vector<bool> check(100);
	vector<int> empty;
	int n = nums.size();

	f(n, empty, nums, check, target);
	
	return ans;
}


int32_t main(){
	


	/* vector<int> nums = {-1,2, 1, -4}; */
	vector<int> nums = {0,0,0};
	int target = 1;
	/* for(auto v : permute(nums)){ */
	/* 	for(auto i : v){ */
	/* 		std::cout << i << " "; */
	/* 	} */
	/* 	std::cout << std::endl; */
	/* } */
	std::cout << permute(nums, target) << std::endl;
	return 0;
}

