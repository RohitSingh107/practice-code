#include <string>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
	int cnt = 0;
	int axor = 0;
	for(char c : allowed){
		axor = axor | (1<<(c - 'a')); 
	}
	for(string s : words){
		bool check = true;
		for(char c : s){
			if(axor & (1<<(c-'a'))){
				continue;
			}
			else{
				check = false;
			}
		}
		if(check) cnt++;
	}
	return cnt;;
}

int32_t main(){
	
	 string allowed = "cad";
	 vector<string> words = {"cc","acd","b","ba","bac","bad","ac","d"};
	 std::cout << countConsistentStrings(allowed, words) << std::endl;

	return 0;
}

