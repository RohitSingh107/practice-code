#include<iostream>
using namespace std;

char upper(char c){
    return c - 'a' + 'A';
}

char lower(char c){
    return c + 'a' - 'A';
}

int check(int result){

    for (int i = 2; i<result; i++){
        if (result % i == 0){
            return 0;
            break;
            
        }
    }
    return 1;
}

int main(){
 
    string s;
    cin>>s;
    int result = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = upper(s[i]);
            result = result + s[i];
            // cout<<s[i]<<endl;
        }
        else{
            s[i] = lower(s[i]);
            result = result -  s[i];
            // cout<<s[i]<<endl;
        }

    }
    if (result < 0){
        result = result * (-1);
    }

    cout<<check(result);

    // cout<<s<<endl;
    // cout<<result<<endl;




    return 0;
}