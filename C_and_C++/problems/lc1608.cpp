#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int specialArray(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for(int i = 1; i<=nums.size(); i++){
		auto ptr = lower_bound(nums.begin(), nums.end(), i);
		int x = nums.end() - ptr;
		/* cout<<*ptr<<" "<<x<<endl; */
		if(i == x){
			return i;
		}
	}
	return -1;

}

int32_t main(){
	vector<int> nums = {0,4,3,0,4};
	std::cout << specialArray(nums) << std::endl;	

	return 0;
}

