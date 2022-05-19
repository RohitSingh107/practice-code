#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;


int minFlips(int a, int b, int c) {
	int cnt = 0;

	while ((a | b) != c) {
		int cbit = c & 1;
		int bbit = b & 1;
		int abit = a & 1;
		if(cbit != (abit | bbit)){
			if(cbit == 1){
				cnt++;
			}
			else{
				if(abit == 1 and bbit == 1){
					cnt = cnt +2;
				}
				else{
					cnt++;
				}
			}
		}
		a = (a>>1);
		b = (b>>1);
		c = (c>>1);
	}
	return cnt;        
}

int32_t main(){
	
	std::cout << minFlips(1, 2, 3) << std::endl;
	return 0;
}

