#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define el endl
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int ar[(int)1e6 + 10];
set<int> tprime;

void t_primes() {
    tprime.insert(4);
    for (int i = 3; i < (int)1e6 + 1; i += 2) {
        if (ar[i] == 0) {
            tprime.insert(i * i);
            for (int j = i; j <= 1e6; j += i) {
                ar[j] = 1;
            }
        }
    }
}

void solve() {
    int x;
    cin >> x;
    t_primes();
    if (tprime.find(x) != tprime.end()) {
        cout << "YES" << el;
    } else {
        cout << "NO" << el;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/inputf.in", "r", stdin);
    freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/outputf.in", "w", stdout);
#endif

    fast_cin();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}