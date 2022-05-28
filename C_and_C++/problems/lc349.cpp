#include <algorithm>
#include <iterator>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool found(vector<int> &nums2, int target){
	int n = nums2.size();
	int lo = 0;
	int hi = n-1;
	int mid;
	while(hi - lo >1){
		mid = (hi+lo)/2;
		if(nums2[mid] < target){
			lo = mid+1;
		}
		else if(nums2[mid] > target){
			hi = mid-1;
		}
		else{
			cout<<"Here "<<target<<endl;
			return true;
		}
	}

	/* cout<<"Here2 "<<target<<endl; */
	return nums2[mid] == target || nums2[lo] == target || nums2[hi] == target;;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	sort(nums2.begin(), nums2.end());
	set<int> ans;
	for(auto i : nums1){
		if(found(nums2, i)){
			ans.insert(i);
		}
	}
	vector<int> final(ans.begin(), ans.end());
	return final;
}

int32_t main(){

	vector<int> nums1 = {4,9,5};
	vector<int> nums2 = {9,4,9,8,4};

	for(auto i : intersection(nums1, nums2)){
		std::cout << i << std::endl;
	}

	

	return 0;
}

