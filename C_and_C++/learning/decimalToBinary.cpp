#include <cmath>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

string decimalToBinary(int x){
	/* if(x < 0){ */
	/* 	int y = ~(abs(x)) + 1; */
	/* 	std::cout << y << std::endl; */
	/* 	return ""; */
	/* } */
	string result = "";
	while (x) {
		/* std::cout << x << std::endl; */
		if(x & 1){
			result = "1" + result;
		}
		else{
			result = "0" + result;
		}
		x >>=1;
	}
	return result;
}

int32_t main(){
	
	int n;
	std::cout << "Enter the number to convert to binary: ";
	cin>>n;

	std::cout << decimalToBinary(n) << std::endl;

	return 0;
}

