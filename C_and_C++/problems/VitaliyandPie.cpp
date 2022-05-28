#include <bits/stdc++.h>
using namespace std;

void printMap(map<char, int> &m){
    cout<<"Size is: "<<m.size()<<endl;
    for(auto p : m){
        cout<<"Key is "<<p.first<<" value is "<<p.second<<endl;
    }
}


int main(){
    int n;
    string s;
    int result = 0;
    // cin>>n;
    // cin>>s;
    // n = 100000;
    // s = "jSdQoEuSdOkRzRoJiYbJiZvBzIoKuFwLjAnNlYhRfCdVjDfVkVlLeEmTzChZlJaPlGbOtFhHpDeXkXpSgIiVrVqOtHxTzSnHgBmXmUiMxCgMdGoTxEmTqZkQiGcVxUzXmFaVqWuAsDkPcVqOoVpSvGwBqQaBoVwLxCrUxTmCrJuOuSiUpVyCjMcSfZcBwDaQuNtGtSkAiVsAtCdUuEcVvSkIzPrGzKbXsNuYrNrFyFvExEnWdWmTrBnHqDoNoIzIpUsJlTiHtPoAuWwInPhOlXsBcGbEiSxLrQsYjArOlXdEqCbRrImWiSnBuKqLnVtNjZsMeKwOnUmCzXnRoOwGcXcKfJrTvLmTyBxQfGmLwDiJuBqAgRzVlEaSpQjVqTtTeUcJkXaDlWaQrGqEjNwHpCeJcUjLqRkOpRhHbCgXsYkZfAoFeHlQoUcUvBtLnVdUyYuXjXcBpWgFsHbXxXgDaQvZcBkCrWqPyNwPbIjFmIzRmNtDzEiKgUx";

    map<char, int> keys;
    int c = 1;
    while(c != n){
        keys[s[2*c -1 -1]] =+ 1;

        auto it = keys.find(std::tolower(s[2*c -1], std::locale()));
       
        if(it == keys.end()){
            result++;
        }
        else if(it->second == 0){
            result++;
        }
        else{
            // keys[std::tolower(s[2*c -1], std::locale())] =- 1;
            keys[std::tolower(s[2*c -1], std::locale())] = keys[std::tolower(s[2*c -1], std::locale())] - 1;
        }

        if(it == keys.end()){
            cout<<"No value"<<endl;
        }
        else{
            cout<<(*it).first<<" "<<it->second<<endl;
        }
        // cout<<<endl;
        c++;
    }    

    printMap(keys);
    // keys[c] = s[n - 1];
    cout<<result<<endl;

    return 0;
}