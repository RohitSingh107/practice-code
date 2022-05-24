#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int q = queries.size();
    int n = arr.size();
    vector<int> ans(q);
    // for(int i = 0; i < q; i++){
    //     // cout<<"Upeer called"<<endl;
    //     for(int j = queries[i][0]; j <= queries[i][1]; j++){
    //         // cout<<"Called"<<endl;
    //         ans[i] ^= arr[j];
    //     }
    // }
    vector<int> pxor(n);
    pxor[0] = arr[0];
    for(int i = 1; i< n; i++){
        pxor[i] = pxor[i-1] ^ arr[i];
    }
    for(auto i : pxor){
        cout<<i<<" ";
    }
    cout<<endl;
    // ans[0] = arr[0];
    for(int i = 0; i< q; i++){
        int l = queries[i][0];
        int r = queries[i][1];
		std::cout << pxor[l] <<" " << pxor[r] << std::endl;
		if(l == 0){
			ans[i] = pxor[r];
		}
		else{

			ans[i] = (pxor[r] ^ pxor[l-1]) ;
		}
        // ans[i] = pxor[l] ;
    }
    return ans;
}

int32_t main(){
	
	vector<int> arr = {1,3,4,8};
	vector<vector<int>> queries = {{0,1}, {1,2}, {0,3}, {3,3}};

	for(auto i : xorQueries(arr, queries)){
		std::cout << i << std::endl;
	}
	

	return 0;
}

