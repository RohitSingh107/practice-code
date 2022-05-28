#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B) {
        int n = A.size();

    int currSum = 0;
    for (int i = 0; i < B; i++) {
        currSum += A[i];
    }
    int ans = currSum;
    int inc = n - 1, exc = B - 1;
    while (inc >= 0 and exc >= 0) {
        currSum += A[inc--];
        currSum -= A[exc--];
        ans = max(ans, currSum);
    }

    return ans;
}

int32_t main() {
    vector<int> A = {5, -2, 3, 1, 2};
    int B = 3;

    cout << solve(A, B);

    return 0;
}