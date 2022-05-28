#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// int solve(unordered_map<int, pair<int, int>> mp, vector<int> ans, int arr[], int i, int n) {
//     for (int j = i; j < n; j++) {
//         // if (mp[arr[j]].second.second > mp[arr[i]].second) {
//         //     // ans[i] = p.first;
//         //     // continue;
//         //     // break;
//         //     return mp[j].first;
//         // }
//         if (mp[arr[j]].second > mp[arr[i]].second) {
//             return arr[j];
//         }
//     }
//     return -1;
// }

int main() {
    // int n = 6;
    // int arr[] = {2, 1, 1, 3, 2, 1};

    int n = 10;
    int arr[] = {5, 1, 2, 3, 2, 5, 5, 4, 5, 2};

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    vector<int> ans(n, -1);

    // for (int i = 0; i < n; i++) {
    //     ans[i] = solve(mp, ans, arr, i, n);
    // }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && mp[arr[st.top()]] < mp[arr[i]]) {
            // ans[st.pop()] = arr[i];
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i : ans) {
        cout << i << " " << endl;
    }

    return 0;
}