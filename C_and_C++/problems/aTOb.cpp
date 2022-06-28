#include <string>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

int cnt = 0;

bool dfs(long long int b, long long int d, long long int current, string &s){

	if(current > d){
		return false;
	}
	if(current == d){
		s = to_string(current) + " " + s;
		cnt++;
		return true;
	}

	if(dfs(b, d, current * 2, s)){
		s = to_string(current) + " " + s;
		cnt++;
		return true;
	}

	if(dfs(b, d, current * 10 + 1, s)){
		s = to_string(current) + " " + s;
		cnt++;
		return true;
	}

	return false;
}

int32_t main(){
	
	/* int b, d; */
	/* cin>>b>>d; */

	/* string ans = to_string(d); */

	/* int cnt = 0; */
	
	/* bool check = true; */

/* 	while (d > 0 and d > b) { */
/* 		if(b == d){ */
/* 			break; */
/* 		} */

/* 		if(d & 1){ */
/* 			if(d % 10 != 1){ */
/* 				check = false; */
/* 				break; */
/* 			} */
/* 			d = d / 10; */
/* 		} */
/* 		else{ */
/* 			d = d/2; */
/* 		} */
/* 		cnt++; */
/* 		ans = to_string(d) + " " + ans; */
/* 	} */

/* 	if(d == b and check){ */
/* 		std::cout << "YES" << std::endl; */
/* 		std::cout << cnt + 1 << std::endl; */
/* 		std::cout << ans << std::endl; */
/* 	} */
/* 	else{ */
/* 		std::cout << "NO" << std::endl; */
/* 	} */

	long long b, d, c;
	cin>>b>>d;

	c = b;

	string s = "";

	if(dfs(b, d, c, s)){
		std::cout << "YES" << std::endl;
		std::cout << cnt << std::endl;
		std::cout << s << std::endl;
	}
	else{
		std::cout << "NO" << std::endl;
	}




	return 0;
}

