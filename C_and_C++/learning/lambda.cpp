#include<bits/stdc++.h>
using namespace std;


int main(){

    cout<<[](int x){return x+2;}(4)<<endl;
    auto sum = [](int x, int y){return x+y;};
    
    cout<<sum(2,3);

    return 0;
}