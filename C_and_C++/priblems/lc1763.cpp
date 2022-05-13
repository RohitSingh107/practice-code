#include <cstdint>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

string longestNiceSubstring(string s) {
	int n = s.size();

	int str=0, end = 0;

	for(int i = 0; i<n; i++ ){
		int a = 0, b = 0;
		for(int j = i; j < n; j++){
			if(s[j] >= 'a' && s[j] <= 'z'){
				a |= (1<<(s[j] - 'a'));
			} 
			else{
				b |= 1 <<(s[j] - 'A');
			}
			if(a == b && j - i > end - str){
				str = i, end = j;
			}
		}
	}   
	return str == end ? "" : s.substr(str, end - str + 1);
}

int32_t main(){
	
	

	return 0;
}

