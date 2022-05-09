#include <algorithm>
#include <string>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

string addBinary(string a, string b) {
	string result;
	int i = a.size() -1, j = b.size() - 1;
	int carry = 0;
	while (i >=0 || j >=0) {
		int sum = carry;
		if(i>=0) sum += a[i--] - '0';
		if(j>=0) sum += b[j--] - '0';
		carry = sum > 1 ? 1 : 0;
		result += to_string(sum%2);
	}
	if(carry) result += to_string(carry);
	reverse(result.begin(), result.end());
	return result;
}

int32_t main(){

	cout<<addBinary("1", "1")<<endl;
	

	return 0;
}

