#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


bool check(vector<int> &v, int target){
	/* cout<<"h3 "<<target<<endl; */
	int lo = 0;
	int hi = v.size() - 1;
	int mid;
	while(hi - lo >1){
		mid = (hi + lo)/2;
		/* cout<<"H5 "<<mid<<" "<<v[mid]<<endl; */
		if(v[mid] < target){
			lo = mid+1;
		}
		else if(v[mid] > target){
			hi = mid - 1;
		}
		else{
			cout<<"h4 "<<target<<endl;
			return true;
		}
	}
	
	return v[lo] == target || v[hi] == target;
}

vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
	sort(bobSizes.begin(), bobSizes.end());
	int aliceTotal = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
	int bobTotal = accumulate(bobSizes.begin(), bobSizes.end(), 0);
	
	int diff = bobTotal - aliceTotal;
	int tex = diff/2;

	int aliceX;

	int bobX;

	for(auto i : aliceSizes){
		/* cout<<"Here 2 "<<i<<" "<<i+tex<<endl; */
		if(check(bobSizes, i + tex)){
			aliceX = i;
			bobX = i + tex;
			/* cout<<"Here1 "<<bobX<<endl; */
			break;
		}
	}
	/* cout<<tex<<" "<<aliceX<<" "<<bobX<<endl; */

	return {aliceX, bobX};
}
int32_t main(){
	
	/* vector<int> aliceSizes = {1,1}, bobSizes = {2,2}; */
	vector<int> aliceSizes = {8,73,2,86,32};
	vector<int> bobSizes = {56,5,67,100,31};
	fairCandySwap(aliceSizes, bobSizes);


	return 0;
}

