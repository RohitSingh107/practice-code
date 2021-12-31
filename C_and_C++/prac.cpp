#include<iostream>
using namespace std;

void staircase(int n) {
    
    for(int i = 1; i<=n; i++){
        // int k = i;
        for (int j =0; j<(n-i); j++){
            cout<<"*";
        }
        for (int j = 0; j<i; j++){
            cout<<"#";
        }
        cout<<endl;
        
        
    }

}

int main(){

    staircase(6);
    
    return 0;
}