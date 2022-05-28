    #include <bits/stdc++.h>
    // #include <cstdio>
    // #include <cstring>
    // #include <cmath>
    // #include <cstring>
    // #include <chrono>
    // #include <complex>
    #define el endl
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    // #define mem(a,val) memset(a,val,sizeof(a))
    #define f first
    // #define s second
    
    using namespace std;
    
    void sol(string s, int len, int one, int z, bool pzo, bool poz){
    
        if(pzo){
            cout<<len/2<<el;
            // continue;
            return;
        }
        else if(poz){
            if(s[len] == '1'){
                cout<<len/2<<el;
                // continue;
                return;
            }
        }
        if(one == z){
            cout<<one-1<<el;
            // continue;
            return;
        }
        else if(one < z){
            cout<<one<<el;
            // continue;
            return;
        }
        else if(one > z){
            cout<<z<<el;
            // continue;
            return;
        }
    }
    
    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            int n; string s;
            cin>>n>>s;
            int one = 0;
            int z = 0;
            for(char i : s){
                if(i == '1'){
                    one++;
                }
                else{
                    z++;
                }
            }
        
            int ans = 0;
            int len = n;
            if(len %2 != 0){
                len--;
            }
            bool pzo = true, poz = true;
            for(int i = 0; i<=len -2; i+=2){
                if(((s[i] == '0') and (s[i+1] == '1'))){
                }
                else{
                    pzo = false;
                }

                if(((s[i] == '1') and (s[i+1] == '0'))){
                }
                else{
                    poz = false;
                }
            }

            // if(pzo){
            //     cout<<len/2<<el;
            //     continue;
            // }
            // else if(poz){
            //     if(s[len] == '1'){
            //         cout<<len/2<<el;
            //         continue;
            //     }
            // }
            // else if(one == z){
            //     cout<<z-1<<el;
            //     continue;
            // }
            // else if(one < z){
            //     cout<<one<<el;
            //     continue;
            // }
            // else if(one > z){
            //     cout<<z<<el;
            //     continue;
            // }
            sol(s, len, one, z, pzo, poz);


        }
        return 0;
    }