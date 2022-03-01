#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    char c;
	    if(c == 'b' || c == 'B'){
	        cout<<"BattleShip";
	    }
	    else if(c == 'c' || c == 'C'){
	        cout<<"Cruiser";
	    }
	    else if(c == 'd' || c == 'D'){
	        cout<<"Destroyer";
	    }
	    else{
	        cout<<"Frigate"<<endl;
	    }
	}
	return 0;
}
