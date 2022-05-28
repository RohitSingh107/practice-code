#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
	sort(A.begin(), A.end());
	int n = A.size();
	if(A[n-1] == 0) return 1;
	for(int i = 0; i<n; i++){
		if(A[i] == n- i -1 && i +1< n && A[i] < A[i+1]){
			return 1;
		}
	}
	return -1;
}

int main(){

	/* vector<int> A = {5,6,2}; */
	vector<int> A = {-4,-2,0,-1, -6};
	/* vector<int> A = {0,0,0}; */
	cout<<solve(A);

	return 0;
}
