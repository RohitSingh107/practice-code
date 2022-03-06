#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		long long int sum =0;
		int n; cin>>n;
		int arr[n];
		for(int i = 0; i<n; i++){
			cin>>arr[i];
			sum += arr[i];
		}
		long long int ans = sum;
		long long int prefix = 0;
		for(int i = 0; i<n; i++){
			prefix += arr[i];
			ans = min(ans, max(prefix, sum - prefix));
		}
		cout<<ans<<endl;
	}
}