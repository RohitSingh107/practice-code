#include<iostream>
using namespace std;
 
void myfunc(int n){
 
    if (n%4 == 0){
        cout<<"Not ok"<<endl;
        myfunc(n-1);
        
    }
    
    else {

        int c;

        c = n/4;

        if (c%4 == 0){
        // cout<<"Not ok"<<endl;
        myfunc(c-1);
        
        }
        
        cout<<c;
    }
    
}
 
int main(){
    
    int n;
    cin>>n;
    
    myfunc(n);
    
    return 0;
}