#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool solve(string a, string b) {
    string a1 = a.substr(2) + a.substr(0, 2);
    string a2 = a.substr(a.size() - 2, 1) + a.substr(a.size() - 1) + a.substr(0, a.size() - 2);
    // cout << a1 << " " << a2 << endl;

    return (b == a1 || b == a2);
}

int main() {
    // string a = "amazon";
    // string b = "azonam";
    string a = "geeksforgeeks";
    string b = "geeksgeeksfor";

    cout << solve(a, b) << endl;

    return 0;
}