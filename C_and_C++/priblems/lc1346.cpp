#include <algorithm>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool checkIfExist(vector<int>& arr) {
	unordered_map<int, int> um;
	for (int i = 0; i < arr.size(); ++i) {
		um[arr[i]]++;
	}
	if(um[0] >=2){
		return true;
	}
    sort(arr.begin(), arr.end());
	int n = arr.size();

	for(auto i : arr){
		int lo = 0;
		int hi = n-1;
		int mid;
		if(i == 0){
			continue;
		}
		while (hi-lo > 1) {
			mid = (hi+lo)/2;
			if(arr[mid] * 2 < i){
				lo = mid+1;
			}
			else if(arr[mid] * 2 > i){
				hi = mid-1;
			}
			else {
				return true;
			}
		}
		if((arr[hi] * 2 == i || arr[lo] * 2 == i) and i != 0){
			return true;
		}
	}
	return false;
}

int32_t main(){
	/* vector<int> arr = {-2,0,10,-19,4,6,-8}; */	
	vector<int> arr = {0,0};	
	std::cout << checkIfExist(arr) << std::endl;	

	return 0;
}

