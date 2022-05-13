#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX = 1000000;
int main() {
    // testcases
    ll T;
    cin >> T;

    // Sieve prime numbers
    vector<bool> all(MAX + 1, true);
    all[0] = all[1] = false;
    for (int i = 2; i * i <= MAX; ++i)
        if (all[i])
            for (int j = i * i; j <= MAX; j += i)
                all[j] = false;

    // map to store squares of prime numbers
    map<ll, bool> tprime;
    for (int i = 2; i < MAX; i++) {
        if (all[i]) {
            tprime[1ll * i * i] = true;
        }
    }
    while (T--) {
        ll a;
        cin >> a;
        // Answer the queries
        if (tprime[a])
            cout << "YES \n";
        else
            cout << "NO \n";
    }

    return 0;
}