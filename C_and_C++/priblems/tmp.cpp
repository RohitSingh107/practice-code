#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int g1 = 0;
	    int g2 = 0;
	    int n;
	    cin>>n;
	    int p[n];
	    for(int i =0; i<n; i++){
	        int x;
	        cin>>x;
	        p[i] = x;
	    }
	    for(int i =0; i< n; i++){
	        if(g1<= g2){
	            g1 = g1 + p[i];
	        }
	        else{
	            g2 = g1 + p[i];
	        }
	    }
	    if(g1>g2){
	        cout<<g1<<endl;
	    }
	    else{
	        cout<<g2<<endl;
	    }
	    
	}
	
	return 0;
}