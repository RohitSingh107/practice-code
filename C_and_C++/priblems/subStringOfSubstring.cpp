#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    string text;
	    cin>>text;
        int ans = 0, c = 0;
        int s = text.size();
        for(int i = 0; i< text.size(); i++){
            if(text[i] != text[0] && text[i] != text[s -1]){
                c = c+1;
                ans = max(c, ans);
                // cout<<"ans is "<<ans<<endl;
            }
            else{
                c = 0;
            }
            // cout<<"out ans is "<<ans<<endl;
        }
        if(ans == 0){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
	}
	return 0;
}
