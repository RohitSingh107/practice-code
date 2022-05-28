
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
            string n;
            cin>>n;
            int even = 0;
            int odd = 0;

            int i = 0;
            while(n[i]){
                // cout<<"NO"<<endl;
                int r = (n[i]-'0') % 10;
                if(r%2 == 0){
                    even++;
                }
                else{
                    odd++;
                }
                // n = n/10;
                i++;
            }

            if(((n[n.size()-1]) - '0')&1){

                if(odd >= 2){
                    cout<<"YES1"<<endl;
                }
                else{
                    cout<<"NO1"<<endl;
                }
            }
            else{
                if(even >= 2){
                    cout<<"YES2"<<endl;
                }
                else{
                    cout<<"NO2"<<endl;
                }
            }




        }
        return 0;
    }