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

    bool dubORzero(vector<int> &nums){
        unordered_map<int,int> um;
        for(int i : nums){
            um[i] += 1;
        }
        for(auto it : um){
            if((it.first == 0) or (it.second >= 2)){
                return true;
            }
        }
        return false;
    }

    bool ones(vector<int> &nums){
        for(int i =0; i<4; i++){
            if((nums[0] - nums[i] ==1 or nums[1] - nums[i] ==1 or nums[2] - nums[i] ==1 or nums[3] - nums[i] ==1) and nums[i] >1){
                return true;
            }
        }
        return false;
    }
    bool nn(vector<int> &nums){
        for(int i : nums){
            if(i<= -1){
                return true;
            }
        }
        return false;
    }

    void solve(vector<int> &nums){

        if(nums[0] == 0 and nums[1] == 0){
            // cout<<" "<<el;
            cout<<-1<<" "<<-1<<el;
            return;
        }

        // cout<<ones(nums)<<" f "<<dubORzero(nums)<<el;
        if((ones(nums)) and (dubORzero(nums))){
            // cout<<ones(nums)<<"sdd "<<dubORzero(nums)<<el;
            int sum = nums[3];
            int pr = nums[2];
            int b = (sum + sqrt(sum*sum - 4*pr))/2;
            int a = sum - b;
            if(a == 0 or b == 0){
                cout<<-1<<" "<<-1<<el;
                return;
            }
            // cout<<a<<" "<<b<<el;
            // int a1, b1;
            int sub, div;
            // cout<<nn(nums)<<el;
            if(nn(nums)){
                // a1 = min(a,b);
                // b1 = max(a,b);
                sub = min(a,b)-max(a,b);
                div = min(a,b)/max(a,b);
                // cout<<a<<" "<<b<<el;
            }
            else{
                // a1 = max(a,b);
                // b1 = min(a,b);

                sub = max(a,b)-min(a,b);
                // int mx = max(a,b);
                div = max(a,b)/min(a,b);
                // int mn = min(a,b);
                // cout<<mx<<" "<<mn<<el;
                // cout<<sub<<" "<<div<<el;
            }
            if(a <= 0 or b <= 0 or a > 10000 or b > 10000){
                cout<<-1<<" "<<-1<<el;
                return;
            }
            else{
                // int div = a1/b1;
                if((div == nums[0] or div == nums[1]) and (sub == nums[0] or sub == nums[1])){
                    cout<<a<<" "<<b<<el;
                }
                else{
                    // cout<<a<<" "<<b<<el;
                    // cout<<sub<<" "<<div<<el;
                    cout<<-1<<" "<<-1<<el;
                }
            }
            // cout<<a1<<" "<<b1<<el;
        }
        else{
            int sum = nums[2];
            int pr = nums[3];
            int b = (sum + sqrt(sum*sum - 4*pr))/2;
            // cout<<a<<" "<<b<<el;
            int a = sum - b;
            // cout<<a<<" "<<b<<el;
            // int a1, b1;
            int sub, div;
            // cout<<nn(nums)<<el;
            if(nn(nums)){
                // a1 = min(a,b);
                // b1 = max(a,b);
                sub = min(a,b)-max(a,b);
                div = min(a,b)/max(a,b);
                // cout<<a<<" "<<b<<el;
            }
            else{
                // a1 = max(a,b);
                // b1 = min(a,b);

                sub = max(a,b)-min(a,b);
                // int mx = max(a,b);
                div = max(a,b)/min(a,b);
                // int mn = min(a,b);
                // cout<<mx<<" "<<mn<<el;
                // cout<<sub<<" "<<div<<el;
            }
            if(a <= 0 or b <= 0 or a > 10000 or b > 10000){

                cout<<-1<<" "<<-1<<el;
                return;
            }
            else{
                // int div = a1/b1;
                // cout<<"ds";
                if((div == nums[0] or div == nums[1]) and (sub == nums[0] or sub == nums[1]) and sub != div){
                    // cout<<"ds";
                    // cout<<nums[0]<<" f "<<nums[1]<<el;
                    // cout<<sub<<" "<<div<<el;
                    cout<<min(a,b)<<" "<<max(a,b)<<el;
                }
                else{
                    // cout<<a<<" "<<b<<el;
                    // cout<<sub<<" "<<div<<el;
                    cout<<-1<<" "<<-1<<el;
                }
            }
            // cout<<a1<<" "<<b1<<el;   
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
            vector<int> nums(4);
            cin>>nums[0];
            cin>>nums[1];
            cin>>nums[2];
            cin>>nums[3];
            sort(nums.begin(), nums.end());
            // int mx = *max_element(nums.begin(), nums.end());
            // for(auto i : nums){
            //     cout<<mx<<el;
            // }
            solve(nums);
            // int mx = nums[nums.size() -1];
            // int smx = nums[nums.size() -2];

            // int n1 = (smx + sqrt(smx*smx - 4*mx))/2.0;
            // cout<<n1<<endl;

        }
        return 0;
    }