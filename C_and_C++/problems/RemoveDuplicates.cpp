// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    string S = "uvvo";

    unordered_map<char, int> ump;
    for (int i = 0; i < S.size(); i++) {
        if (ump[S[i]] == 1) {
            S.erase(i, 1);
            i--;
        } else {
            ump[S[i]]++;
        }
    }

    cout << S << endl;

    return 0;
}