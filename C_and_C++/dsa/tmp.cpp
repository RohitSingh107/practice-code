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
    #define s second
    
    using namespace std;
    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            int n;
            cin>>n;
            int ans = 0;
            n = 73452;

            while(n > 0){
                // cout<<"NO"<<endl;
                int r = n % 10;
                if(r%2 == 0){
                    ans++;
                }
                n = n/10;
                if(ans >= 2){
                    cout<<"YES"<<endl;
                }
                return 0;
            }

            cout<<"NO"<<endl;



        }
        return 0;
    }