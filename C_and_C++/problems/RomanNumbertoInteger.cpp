#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int val(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int solve(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        int v1 = val(s[i]);
        if (i + 1 == s.size()) {
            res += v1;
            return res;
        } else {
            int v2 = val(s[i + 1]);
            if (v1 < v2) {
                res = res + v2 - v1;
                i++;
            } else {
                res += v1;
            }
        }
    }
    return res;
}

int main() {
    string s = "MMMIM";

    cout << solve(s) << endl;

    return 0;
}