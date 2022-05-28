#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n>>k;

        long long int total = 0;
        multiset<long long int> bags;

        while(n--){
            long long c;
            cin>>c;
            bags.insert(c);
        }
        while(k--){
            auto max_it = (--bags.end());
            long long max_can = *max_it;
            total += max_can;
            bags.erase(max_it);
            bags.insert(max_can / 2);
        }
        cout<<total<<endl;
    }


    return 0;
}