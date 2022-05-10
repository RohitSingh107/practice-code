#include <iostream>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


vector<int> findErrorNums(vector<int>& nums) {
	int n = nums.size();
	vector<int> ans(2);

	int tmp = 0;
	for(auto i : nums){
		tmp ^= i;
	}
	for(int i = 1; i<= n; i++){
		tmp ^= i;
	}


	int tmp2 = tmp;
	int j = 0;
	while(!(tmp2 & 1)){
		/* std::cout << tmp2 << std::endl; */
		tmp2 =tmp2>>1;
		j++;
	}
	int buck1 = 0;
	int buck2 = 0;
	for(auto i : nums){
		if(i & (1<<j)){
			/* std::cout << "Odd: "<<i << std::endl; */
			buck1 ^= i;
			/* std::cout << std::endl; */
		}
		else{
			/* std::cout << "Even: "<<i << std::endl; */
			buck2 ^= i;
			/* std::cout << std::endl; */
		}
	}

	/* cout<<tmp<<endl; */

	/* std::cout << buck1 <<" "<<buck2<< std::endl; */

	int p1 = 0;
	int p2 = 0;
	for(int i = 1; i<=n; i++){
		if(i & (1<<j)){
			/* std::cout << "Odd: "<<i << std::endl; */
			p1 ^= i;
			/* std::cout << std::endl; */
		}
		else{
			/* std::cout << "Even: "<<i << std::endl; */
			p2 ^= i;
			/* std::cout << std::endl; */
		}
	}
	ans[1] = buck1 ^ p1;
	ans[0] = tmp ^ ans[1];

	return ans;
}

int32_t main(){
	
	vector<int> nums= {1,2,2,4};

	for(auto i : findErrorNums(nums)){
		std::cout << i << std::endl;
	}
	/* findErrorNums(nums); */

	return 0;
}

