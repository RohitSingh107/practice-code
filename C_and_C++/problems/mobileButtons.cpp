#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "HEY U";

    unordered_map<char, string> mp = {{'A', "2"}, {'B', "22"}, {'C', "222"}, {'D', "3"}, {'E', "33"}, {'F', "333"}, {'G', "4"}, {'H', "44"}, {'I', "444"}, {'J', "5"}, {'K', "55"}, {'L', "555"}, {'M', "6"}, {'N', "66"}, {'O', "666"}, {'P', "7"}, {'Q', "77"}, {'R', "777"}, {'S', "7777"}, {'T', "8"}, {'U', "88"}, {'V', "888"}, {'W', "9"}, {'X', "99"}, {'Y', "999"}, {'Z', "9999"}, {' ', "0"}};
    string ans = "";
    for (char c : s) {
        // s.push_back(mp[c]);
        ans.append(mp[c]);
    }
    cout << ans << endl;

    return 0;
}