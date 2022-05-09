#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << (12 >> 2) << endl;
    cout << (12 << 1) << endl;
    cout << (1024 >> 3) << endl;

    int x = 24;
    int y = 7;

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    cout << x << " " << y << endl;

    int six = 309;

    cout << (six & (1 << 6)) << endl;  // ith bit

    cout << (six | (1 << 3)) << endl;  // Bit Set

    cout << (six & ~(1 << 4)) << endl;  // Bit Clear

    // Bits required to change N1 to N2

    int n1 = 789;  // 1100010101
    int n2 = 423;  //  110100111
    // int n1 = 4;
    // int n2 = 6;

    int msk = n1 ^ n2;

    int i = 0;
    while (msk) {
        i++;
        msk = msk & (msk - 1);
    }
    cout << i << endl;

	for(char c = 'A'; c <= 'E'; ++c){
		cout<<c<<endl;
	}

    return 0;
}
