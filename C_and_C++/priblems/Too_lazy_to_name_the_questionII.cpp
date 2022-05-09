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
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> pv(n);
    set<pair<int, int>> ps;
    for (int i = 0; i < n; i++) {
        // int x, y;
        cin >> pv[i].first >> pv[i].second;
        ps.insert({pv[i]});
    }
    int a_min = INT_MAX, a_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair<int, int> p1 = pv[i];
            pair<int, int> p2 = pv[j];

            if (p1.first == p2.first) {
                continue;
            }
            if (p1.second == p2.second) {
                continue;
            }
            if (p1.first > p2.first) swap(p1, p2);
            int x1 = p1.first, y1 = p2.second;
            int x2 = p2.first, y2 = p1.second;
            if (ps.count({x1, y1}) && ps.count({x2, y2})) {
                int area = abs((p2.second - p1.second) * (p2.first - p1.first));
                // cout << area << el;
                a_max = max(a_max, area);
                a_min = min(a_min, area);
            }
        }
    }
    // cout << a_max << " " << a_min;
    if (a_min == INT_MAX) {
        cout << -1 << el;
    } else {
        cout << a_max - a_min << el;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/inputf.in", "r", stdin);
    freopen("/home/rohits/mydata/code/C_and_C++/sublime_editor/outputf.in", "w", stdout);
#endif

    fast_cin();
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}