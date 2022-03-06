#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int x1, y1, x2, y2, k;
		cin>>x1>>y1>>x2>>y2>>k;
		int least_moves = abs(x2-x1) + abs(y2-y1);
		int extras = k - least_moves;
		if(extras % 2 == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}