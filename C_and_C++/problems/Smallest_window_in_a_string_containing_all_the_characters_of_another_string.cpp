// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    // string S = "zoomlazapzo";
    // string P = "oza";
    // string S = "timetopractice";
    // string P = "toc";
    string S = "mpsbqedzsqyskjqydomdanqfmtqri";
    string P = "rrbqrnbbzyijnwfnimshbjimbfe";

    int n = S.size();
    unordered_map<char, int> ump;
    unordered_map<char, int> ums;

    for (char c : P) {
        ump[c]++;
    }

    string ans = "";
    int dm = P.size();
    int cm = 0;
    int i = -1, j = -1;

    while (true) {
        bool f1 = false;
        bool f2 = false;
        while (i < n - 1 && cm < dm) {
            i++;
            ums[S[i]]++;
            if (ums[S[i]] <= ump[S[i]]) {
                cm++;
            }
            f1 = true;
        }
        while (j < i && cm == dm) {
            string pans = S.substr(j + 1, i - j);
            if (ans.size() == 0 || pans.size() < ans.size()) {
                ans = pans;
            }
            j++;
            ums[S[j]]--;
            if (ums[S[j]] < ump[S[j]]) {
                cm--;
            }
            f2 = true;
        }

        if (f1 == false && f2 == false) {
            break;
        }
    }
    cout << ans.size() << endl;

    return 0;
}