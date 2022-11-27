
#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
    int p2 = 0;
    int p1 = 1;
    int c;

    for (int i = 2; i < n; i++) {
        c = p1 + p2;

        p2 = p1;
        p1 = c;
    }

    return p1;
}

int main() {
    cout << fib(19) << endl;
    return 0;
}