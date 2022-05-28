#include <vector>
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") */
/* #pragma GCC optimize("unroll-loops") */
#include <bits/stdc++.h>  

using namespace std;

bool check(vector<int> &arr2, int i, int d){
	bool flag = true;
	int lo =0, hi = arr2.size()-1, mid;
	while (hi-lo > 1) {

		/* cout<<hi<<" - "<<lo<<" = "<<hi-lo<<endl; */
		mid = (hi+lo)/2;
		cout<<arr2[mid]<<" - "<<i<<" = "<<abs(arr2[mid] - i)<<endl;
		if(abs(arr2[mid] - i) <= d){
			flag = false;
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	cout<<arr2[hi]<<" "<<arr2[lo]<<" "<<i<<endl;
	if(abs(arr2[lo] - i) <= d){
		flag = false;
	}	
	if(abs(arr2[hi] - i) <= d){
		flag = false;
	}
	/* return abs(arr1[hi] - i) <= d || abs(arr1[lo] -i) <= d ; */
	return flag;
}

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
	int ans = 0;
	for(auto i : arr1){
		if(check(arr2, i, d)){
			ans++;
		}
	}
	return ans;
}

int32_t main(){
	
	vector<int> arr1 = {-3,-3,4,-1,-10}, arr2 = {7,10};
	int d = 12;

	/* vector<int> arr1 = {4,-3,-7,0,10}, arr2 = {10}; */
	/* int d = 69; */

	std::cout << findTheDistanceValue(arr1, arr2, d) << std::endl;

	return 0;
}

