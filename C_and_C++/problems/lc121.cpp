#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int maxProfit(vector<int>& prices) {
	/* int ans = INT_MIN; */
	/* int bp = INT_MAX; */
	/* int bpi = 0; */
	/* int bsi = 0; */
	/* int bs = prices[prices.size() - 1]; */

	/* for(int i = 0; i< prices.size(); i++){ */

	/* 	std::cout << "bp is " << bp << " best bs is " << bs  << std::endl; */

	/* 	if(i == 0){ */
	/* 		bp = prices[i]; */
	/* 	} */

	/* 	if(prices[i] < bp){ */
	/* 		bp = prices[i]; */
	/* 		bpi = i; */
	/* 	} else{ */
	/* 		if(prices[i] > bs and i != 0){ */
	/* 			bs = prices[i]; */
	/* 		} */
			
	/* 	} */
	/* } */
	/* std::cout << bp << ' ' << bs << std::endl; */

	/* return bs - bp; */


	int max_array[10005];
	for(int i = 0; i< prices.size(); i++){
		if(max_array[prices[i]] < prices[i]){
			max_array[prices[i]]
		}
	}
}

int32_t main(){

	/* vector<int> nums = {7,6,4,3,1}; */
	vector<int> nums = {2,4,1};
	std::cout << maxProfit(nums) << std::endl;
	
	
	

	return 0;
}

