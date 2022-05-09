#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#define ll long long int
#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#include <cmath>
using namespace std;


map<long long int, long long int> mp;

int N = 1000005;

/* ll coll[1000005][1000005]; */

ll MOD = 1000000007;



void f(long long int m, long long int x){
	/* cout<<m<<endl; */
	if(m == 1){
		return;
	}

	mp[x]--;
	
	mp[x+1]++;
	f(m - 1, x+1);

	mp[x-1]++;
	f(m - 1, x-1);
}

int binomialCoeff(ll n, ll r)
{
 
    if (r > n)
        return 0;
    long long int m = 1000000007;
    long long int inv[r + 1] = { 0 };
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;
 
    // Getting the modular inversion
    // for all the numbers
    // from 2 to r with respect to m
    // here m = 1000000007
    for (ll i = 2; i <= r; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
 
    ll ans = 1;
 
    // for 1/(r!) part
    for (ll i = 2; i <= r; i++) {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }
 
    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (ll i = n; i >= (n - r + 1); i--) {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}

int32_t main(){
	int coll[N][N];
	ll n = 5;
	ll r = 4;
	ll k = (n/2) - (r/2);

	mp[0]++;	
	f(1+n ,0);

	for(auto p : mp){
		cout<<p.first<<" "<<p.second<<endl;
	}
	
	cout<<"value is "<<binomialCoeff(n,2)<<endl;
	/* cout<<"value is "<<binomialCoeff(n,(n/2) - (r/2))<<endl; */
	/* cout<<"val is "<< 1/((n+1)*std::beta(n-k+1, k+1))<<endl; */

	N = 15;
	
	for(int i = 1; i< N; i++){
		coll[i][0] = 1;	
	}

	/* coll[0][0] = 0; */
	/* coll[1][1] = 1; */

	/* for(int i = 1; i< 15; i++){ */
	/* 	for(int j = 1; j<=i && j< 15; j++){ */
	/* 		cout<<j<<" "<<endl; */
	/* 		if(i == 1 && j == 1){ */
	/* 			coll[i][j] = 1; */
	/* 		} */
	/* 		else{ */
	/* 			/1* cout<<i<< " "<<j<<endl; *1/ */
	/* 			/1* coll[i][j] = (coll[i-1][j] + coll[i-1][j-1]) % MOD; *1/ */
	/* 			/1* coll[i][j] = 9; *1/ */
	/* 		} */
	/* 	} */
		/* cout<<i<<endl; */
	/* } */
	for (int i = 1; i < 15; i++) {
		for(int j = 1; j<=i && j< 15; j++){
			cout<<i<<" "<<j<<endl;
			if((i == 1) or (j == 1)){
				cout<<i<<" "<<j<<endl;
			}
		}
	}	

	/* cout<<"value is "<< coll[5][2]<<endl; */


	return 0;
}