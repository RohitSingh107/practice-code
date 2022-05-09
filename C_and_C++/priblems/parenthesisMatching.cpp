#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool solve(string &p) {
    unordered_map<char, int> br = {
        {'[', -3},
        {'{', -2},
        {'(', -1},
        {')', 1},
        {'}', 2},
        {']', 3}};

    stack<char> st;
    for (char c : p) {
        if (br[c] < 0) {
            st.push(c);
        } else {
            if (!st.empty() && br[c] + br[st.top()] == 0) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    // string p = "{([])}";
    string p = "()[]{}";

    cout << solve(p) << endl;

    return 0;
}