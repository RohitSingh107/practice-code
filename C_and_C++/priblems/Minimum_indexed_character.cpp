#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int solve(string str, string patt) {
    int ans = 1000000;
    for (int i = 0; i < patt.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == patt[i]) {
                ans = min(ans, i);
                continue;
                return j;
            }
        }
    }
    if (ans == 1000000) {
        ans = -1;
    }
    return ans;
    // cout << ans << endl;
}

int main() {
    string str = "hasjkhflaskdf";
    string patt = "sdlkjfshd";

    int ans = solve(str, patt);
    cout << ans << endl;

    return 0;
}