#include <bits/stdc++.h>
using namespace std;

void printMap(map<char, int> &m){
    cout<<"Size is: "<<m.size()<<endl;
    for(auto p : m){
        cout<<"Key is "<<p.first<<" value is "<<p.second<<endl;
    }
}

int main(){

    // string str1 = "#" ;
    // string str2 = "#@@@#**#";
    // string str1 = "*@#*";
    // string str2 = "*#";
    string str1 = "@#**#@@#*";
    string str2 = "*@@*@##@@*";

    int s1;
    int s2 = 0;

    int res = 0;
   
    if(str1.length() <= str2.length()){
        for(int i =0; i< str1.length(); i++){
            for(int j = s2 +1; j < str2.length(); j++){
                if(str2[j] == str1[i]){
                    res++;
                    s2 = j;
                    break;
                }
            }
        }
    }
    else {
        for(int i =0; i< str2.length(); i++){
            for(int j = i; j < str1.length(); j++){
                if(str1[j] == str2[i]){
                    res++;
                    break;
                }
            }
        }
    }


    cout<<res<<endl;
    // printMap(m);


    return 0;
}