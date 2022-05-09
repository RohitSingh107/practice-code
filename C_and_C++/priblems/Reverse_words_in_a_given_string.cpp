// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    string S = "i.like.this.program.very.much";

    string ans;
    int od = S.size() - 1;
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == '.') {
            ans.append(S.substr(i + 1, od - 1));
            ans.push_back('.');
            od = 0;
        }
        od++;
    }
    ans.append(S.substr(0, od - 1));

    cout << ans << endl;

    return 0;
}
