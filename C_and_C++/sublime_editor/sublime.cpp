#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		set<int> s;
		for(int i =l; i<= r; i++){
			for(int j = i; j<=r; j++){
				s.insert(i+j);
			}
		}
		cout<<s.size()<<endl;
	}
	return 0;
}