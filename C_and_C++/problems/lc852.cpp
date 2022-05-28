#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

bool check(vector<int> &arr, int mid){
	if(mid == 0){
		return true;
	}
	return arr[mid-1] < arr[mid];
}

int peakIndexInMountainArray(vector<int>& arr) {
	int n = arr.size();
	int lo = 0;
	int hi = n-1;
	int mid;
	while(hi - lo > 1){
		mid = (hi +lo)/2;
		if(check(arr, mid)){
			lo = mid;
		}
		else{
			hi = mid;
		}
	}
	return lo;
}

int32_t main(){
	
	vector<int> arr = {1,5,7, 2};
	std::cout << peakIndexInMountainArray(arr) << std::endl;
	

	return 0;
}

