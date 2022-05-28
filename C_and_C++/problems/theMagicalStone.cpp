#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll fac[1000001];

ll pwr(ll a, ll b, ll mod){ 
	ll x = 1, y = a; 
	while (b > 0){ 
		if (b%2){ 
			x = (x*y)%mod; 
		} 
		y = (y*y)%mod; 
		b /= 2; 
	} 
	return x%mod; 
}	 
 
ll mI(ll n, ll mod){ 
	return pwr(n, mod-2, mod); 
} 
 
ll nCr(ll n, ll k, ll mod){ 
	return (fac[n]*((mI(fac[k], mod) * mI(fac[n-k], mod)) % mod)) % mod; 
}

int main()
{
	
	fac[0] = 1;
	fac[1] = 1;
	for(ll i = 2; i< 1000001; i++){
		fac[i] = fac[i-1] * i % 1000000007;
	}


	/* int n = 150000; */
	/* int r = (n/2) - (48/2); */
	long long int p = 1000000007;
	/* std::cout << nCr(n, r, p) << std::endl; */


	int t;
	cin>>t;
	while (t--) {

	int n, l , r;
	cin>>n>>l>>r; 
	/* int p = 1000000007; */
	if(n & 1){
		for(int i = l; i<=r; i++){
			if(i & 1){
				/* cout<<bc(n, (n/2) - (abs(i)/2))<<" "; */
				cout<<nCr(n, (n/2) - (abs(i)/2), p)<<" ";
				/* bc(n, (n/2) - (abs(i)/2)); */
				/* std::cout << " "; */
				
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
	else{
		for(int i = l; i<=r; ++i){
			if(i & 1){
				cout<<"0 ";
			}
			else{
				/* cout<<bc(n, (n/2) - (abs(i)/2))<<" "; */
				cout<<nCr(n, (n/2) - (abs(i)/2), p)<<" ";
				/* bc(n, (n/2) - (abs(i)/2)); */
				/* std::cout << " "; */
			}
		}
		cout<<endl;
	}

	}

	return 0;
}
