#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 6;
    int a[] = {4, 5, 5, 25, 7, 8};

    vector<int> v = {4, 5, 5, 25, 7, 8};

    set<int> s = {4, 5, 5, 25, 7, 8};

    map<int, int> m = {{7, 3}, {9, 37}, {6, 2}, {5, 27}};

    sort(a, a + n);
    sort(v.begin(), v.end());

    // Array
    int *ptr = upper_bound(a + 4, a + n, 4);
    if (ptr == a + n) {
        cout << "Not found";
        return 0;
    }
    cout << (*ptr) << endl;

    // Vector
    auto it = lower_bound(v.begin(), v.end(), 6);
    if (it == v.end()) {
        cout << "Not found";
        return 0;
    }
    // cout << (*it) << endl;
    // cout << (it) << endl;
    cout << *it << " " << (it - v.begin()) << endl;

    // Set
    auto sit = s.upper_bound(5);
    if (sit == s.end()) {
        cout << "Not found";
        return 0;
    }
    cout << (*sit) << endl;

    // Map
    auto mit = m.upper_bound(4);
    if (mit == m.end()) {
        cout << "Not found";
        return 0;
    }
    cout << (*mit).first << endl;

    return 0;
}