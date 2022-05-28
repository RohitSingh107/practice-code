#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    // string S = "geeksforgeeks";
    string S = "aldshflasghdfasgfkhgasdfasdgvfyweofyewyrtyefgv";
    // string S = "aldshflas";
    // string S = "abcd";
    // string S = "aewergrththy";

    unordered_map<char, int> ump;

    int n = S.size();
    int ans = 1;
    int i = 0, j = 0;
    ump[S[0]]++;
    while (j != n - 1) {
        if (ump[S[j + 1]] == 0) {
            j++;
            ump[S[j]] = 1;
            ans = max(ans, j - i + 1);
        } else {
            ump[S[i]]--;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}