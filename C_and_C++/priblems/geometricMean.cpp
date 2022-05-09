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

    // vector<vector<int>> vsa;
    void printPowerSet(vector<int> &set, int set_size, vector<vector<int>> &vsa)
    {
        /*set_size of power set of a set with set_size
        n is (2**n -1)*/
        unsigned int pow_set_size = pow(2, set_size);
        int counter, j;
     
        /*Run from counter 000..0 to 111..1*/
        for(counter = 0; counter < pow_set_size; counter++)
        {
        vector<int> tmp;
        for(j = 0; j < set_size; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from set */
            if(counter & (1 << j))
                // cout << set[j]<<" ";
                tmp.push_back(set[j]);
        }
        // cout << endl;
        vsa.push_back(tmp);
        }
    }

    int nthRoot(vector<int> &v)
    {
        int N = v.size();
        int A = 1;
        for(int i : v){
            A *= i;
        }
        double xPre = rand() % 10;
     
        double eps = 1e-3;
     
        double delX = INT_MAX;
     
        double xK;
     
        while (delX > eps)
        {
            xK = ((N - 1.0) * xPre +
                  (double)A/pow(xPre, N-1)) / (double)N;
            delX = abs(xK - xPre);
            xPre = xK;
        }
        return int(xK);
    }


    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            int n; cin>>n;
            int k; cin>>k;
            vector<int> v(n);
            for(int i = 0; i<n; i++){
                cin>>v[i];
            }
            // vector<vector<int>> vsa;
            // for(int i = 0; i<n; i++){
            //     for(int j = i; j<n; j++){
            //         vector<int> tmp;
            //         for(int k =i; k<=j; k++){
            //             tmp.push_back(v[k]);
            //             // cout<<v[k]<<" ";
            //         }
            //         // cout<<el;
            //         vsa.push_back(tmp);

            //     }
            // }
            // vsa = {{}};
            v = {3,3,3};
            n = 3;
            vector<vector<int>> vsa;
            printPowerSet(v, v.size(), vsa);
            // cout<<vsa[1].size()<<el;
            int ans = 0;
            for(int i = 0; i< vsa.size(); i++){
                for(int j =0; j< vsa[i].size(); j++){
                    cout<<vsa[i][j]<<" ";
                }
                cout<<el;
                // if((nthRoot(vsa[i]) == k ) and (vsa[i].size() != 0)){
                //     ans++;
                // }
            }
            cout<<ans<<endl;
        }
        return 0;
    }