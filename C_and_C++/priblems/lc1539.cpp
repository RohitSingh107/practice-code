#include <codecvt>
#include <iostream>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool check(vector<int> &arr, int target){
	int lo = 0;
	int hi = arr.size() - 1;
	int mid;
	while(hi - lo > 1){
		mid = (hi+lo)/2;
		if(arr[mid] < target){
			lo = mid + 1;
		}
		else if (arr[mid] > target) {
			hi = mid - 1;
		}
		else {
			return false;
		}
	}
	return !(arr[lo] == target || arr[hi] == target);

} 

int findKthPositive(vector<int>& arr, int k) {
	int N = 1001;
	int cnt = 0;
	int i =1; 
	int ans;
	while(cnt != k and i != N){
		if(check(arr, i)){
			cnt++;
			if(cnt == k){
				ans =  i;
				break;
			}
		}
		i++;
	}
	return ans;
}


int32_t main(){
	vector<int> arr = {1,2,3,4};
	int k = 2;
	
	std::cout << findKthPositive(arr, k) << std::endl;
	return 0;
}

