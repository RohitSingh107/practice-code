#include <bits/stdc++.h>
using namespace std;

#define int long long


int solve()
{
    const int M = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(7)); // dp[i][j] -> number of subsequences of first i elements that have remainder j on dividing by 7
    dp[0][0] = 1;                                  // empty subsequence has remainder 0, as its value is 0
    for (int i = 0; i < n; i++)
    {
        int l = (int)to_string(a[i]).size();
		std::cout <<"l is " << l << std::endl;
        int p = 1;
        while (l--)
            p *= 10; // p is 10^l, implement it differently (by using your own logic) to escape plag
        for (int j = 0; j < 7; j++)
        {
            int use = (j * p + a[i]) % 7;                     // if we use ith element then use will be the new remainder
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % M;     // don't use ith element
            dp[i + 1][use] = (dp[i + 1][use] + dp[i][j]) % M; // use ith element
        }
    }
    cout << (dp[n][0] - 1 + M) % M << '\n'; // subtract one (empty subsequences are not counted).
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
} 
