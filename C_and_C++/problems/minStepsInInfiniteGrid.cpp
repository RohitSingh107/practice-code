#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;


int solve(int x1, int y1, int x2, int y2) {
	int xdiff = abs(x2 - x1);
	int ydiff = abs(y2 - y1);

	return max(xdiff, ydiff);

}

int main(){

	/* cout<<solve(-7, 1, -2, -3); */
	vector<int> a = { 4, 8, -7, -5, -13, 9, -7, 8 };
	vector<int> b = { 4, -15, -10, -3, -13, 12, 8, -8 };
	int ans = 0;
	int x = a[0];
	int y = b[0];
	for(int i = 1; i<a.size(); i++){
		ans += solve(x, y, a[i], b[i]);
		x = a[i];
		y = b[i];
	}
	cout<<ans<<endl;

	
	
	return 0;
}
