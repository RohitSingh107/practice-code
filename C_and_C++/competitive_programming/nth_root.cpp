#include <bits/stdc++.h>

using namespace std;

double eps = 1e-6;

double mult(double mid, int n){
	double ans = 1;
	while(n--){
		ans = ans * mid;
	}
	return ans;
}

int main(){
	
	double x = 27;
	int n = 3;
	double lo = 1, hi = x, mid;

	while(hi - lo > eps){
		mid = (hi+ lo)/2;
		if(mult(mid, n) < x){
			lo = mid;
		}
		else {
		hi = mid;
		}
	}
	cout<<lo<<endl;
	cout<<hi<<endl;

	
	return 0;
}
