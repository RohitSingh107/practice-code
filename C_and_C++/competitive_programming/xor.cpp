#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Not repeating twice
    vector<int> vi = {5, 4, 1, 4, 3, 5, 1};
    int ans = 0;
    for (int i : vi) {
        ans = ans ^ i;
    }
    cout << ans << endl;

    // Not repeating twice (2 integers)
    vector<int> vi2 = {5, 4, 1, 4, 3, 5, 1, 2};
    int ans2 = 0;
    for (int i : vi2) {
        ans2 = ans2 ^ i;
    }

    vector<int> v1;
    vector<int> v2;
    // cout << ans << endl;
    int tmp1 = ans2;
    int one = 0;
    while (tmp1 & 1) {
        one++;
        tmp1 = tmp1 >> 1;
    }
    for (int i : vi2) {
        // ans2 = ans2 ^ i;
        if ((i & ~(1 << one)) == 0) {
            v1.push_back(i);
        } else {
            v2.push_back(i);
        }
    }
    int fn = 0;
    for (int i : v1) {
        fn = fn ^ i;
    }
    fn = fn ^ ans2;

    int sn = ans2 ^ fn;
    cout << fn << " " << sn << endl;

    return 0;
}