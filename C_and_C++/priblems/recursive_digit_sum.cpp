#include <bits/stdc++.h>
#include <string>

using namespace std;

long long digit_sum(long long n){

    if(n==0){
        return 0;
    }
    return (n % 10) + digit_sum(n / 10);
}

bool indicator = false;
string f;
long long l = 0;

long superDigit(string n, int k) {
    f = n;

    if(not indicator){
        for(int i = 1; i<k; i++){
            f = f + n;
        }
        cout<<f<<endl;
        indicator = true;
    }
    
    l = std::stol(f);

    if (l / 10 == 0){
        return l;
    }
    else{
        return superDigit(std::to_string(digit_sum(l)), k);
    }
}


int main(){
    
    // cout<<digit_sum(123)<<endl;

    cout<<superDigit("593", 6)<<endl;
    


    return 0;
}