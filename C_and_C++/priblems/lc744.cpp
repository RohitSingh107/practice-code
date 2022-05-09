#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
	char ans;
	int lo = 0;
	int hi = letters.size() - 1;
	int mid = 0;
	while(hi - lo > 1){
		mid = (hi + lo)/2;
		if(letters[mid] <= target){
			lo = mid+1;
		}
		else if (letters[mid] > target) {
			hi = mid;
		}
	}
	ans = letters[mid];
	if(letters[lo] > target){
		ans = letters[lo];
	}
	if(letters[letters.size() -1] <= target){
		ans = letters[0];
	}
	if(letters[hi] > target and letters[lo] <= target){
		ans = letters[hi];
	}

	cout<<letters[lo]<<" "<<letters[mid]<< " "<<letters[hi]<<endl;
	return ans;
}

int32_t main(){
	
	vector<char> letters = {'e', 'e', 'e', 'k', 'q', 'q', 'q', 'v', 'v', 'y'};
	char target = 'q';
	/* vector<char> letters = {'c', 'f', 'j'}; */
	/* char target = 'z'; */
	std::cout << nextGreatestLetter(letters, target) << std::endl;

	return 0;
}

