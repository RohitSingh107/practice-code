#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a,
         pair<int, int> b) { // first in ascending and second in descending
  if (a.first != b.first) {
    // if(a.first> b.first){
    //     return true;
    // }
    // return false;
    return a.first > b.first;
  } else {
    // if(a.second < b.second){
    //     return true;
    // }
    // return false;
    return a.second < b.second;
  }
}

int main() {

  int a[] = {6, 5, 14, 4, 3, 25, 2, 7, 8, 5};
  int n = 10;

  vector<int> v;
  v = {65, 15, 14, 34, 3, 25, 4, 2, 17, 8, 35};

  sort(a, a + n);
  sort(v.begin() + 3, v.end());

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  vector<pair<int, int>> vp;
  vp = {{4, 3}, {5, 5}, {5, 3}, {25, 6}, {7, 9}, {8, 5}};

  sort(vp.begin(), vp.end(), cmp);

  for (auto p : vp) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
