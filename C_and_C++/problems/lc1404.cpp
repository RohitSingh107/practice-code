#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int numSteps(string s) {
	int cnt = 0;
	while(s.size() != 1){
		bool did = false;
		if(s.back() == '0'){
			/* std::cout <<"zero " << s << std::endl; */
			s.pop_back();
			cnt++;
		}
		else{
			/* std::cout <<"one " << s << std::endl; */
			for(int i = s.size() -1; i >= 0; i--){
				if(s[i] == '0'){
					s[i] = '1';
					did = true;
					break;
				}
				else{
					s[i] = '0';
				}
			}
			if(!did){
				s = "1" + s;
			}

			cnt++;
		}
	}       
	/* std::cout << s.back() << std::endl; */
	return cnt;
}

int32_t main(){
	
	std::cout << numSteps("10") << std::endl;	

	return 0;
}

