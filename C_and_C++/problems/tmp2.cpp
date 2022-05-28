#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;



const long long int N = 1000001;

// long long int coll[10000][10000];
vector<vector<int>> coll(N, vector<int> (N));

int32_t main(){
	// int N = 15;
	long long int MOD = 1000000007;

	// N = 15;
	
	for(int i = 1; i< N; i++){
		coll[i][0] = 1;	
	}

	for(int i = 1; i< N; i++){
		coll[i][0] = 1;	
	}
	for (int i = 1; i < N; i++) {
		for(int j = 1; j<=i && j< N; j++){
			if(i == 1 && j == 1){
				coll[i][j] = 1;
			}
			else{

	 			coll[i][j] = (coll[i-1][j] + coll[i-1][j-1]) % MOD; 
			} 
			// cout<<"After "<<i<<" "<<j<<" "<<coll[i][j]<<endl;

		}
	}	

	cout<<"value is "<< coll[5][2]<<endl;


	return 0;
}
