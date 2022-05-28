#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
            int dp[33][n+1];
            for(int i=1;i<=n;i++){
                int ty ;
                cin >> ty;
				
				for (int j = 0; j<33;  j++) {
					dp[j][i] = dp[j][i-1];
				}
				int p = 32;
				if(ty != 0){
					p = (int)log2(ty);
				}
                dp[p][i]++;
            }
            int query;
            cin >> query;
            for(int i =0;i<query;i++){
                int l,r,x;
                cin>>l;
                cin>>r;
                cin>>x;
                int p = 32;
                int c = 0;
				if(x != 0){
					p = (int)log2(x);
				}
				c = dp[p][r] - dp[p][l-1];
                int a =(r-l+1)-c;
                cout << a << endl;
            }
    }
	return 0;
}
