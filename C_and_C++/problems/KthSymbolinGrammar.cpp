#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    if (n == 1 && k == 1) {
        return 0;
    }

    int mid = pow(2, n - 1) / 2;
    if (mid >= k) {
        return solve(n - 1, k);
    } else {
        return !(solve(n - 1, k - mid));
    }
}

int main() {
    int n = 4, k = 8;
    // vector<string> vs(n);
    // string s = "01";

    int t = solve(n, k);
    cout << t << endl;

    return 0;
}