#include <string>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string> &tokens) {

  std::stack<int> s;
  s.push(stoi(tokens[0]));

  int i = 1;
  while (!s.empty() and i < tokens.size()) {
    string e = tokens[i];
    if (e == "+") {
      int x = s.top();
      s.pop();
      int y = s.top();
      s.pop();
      s.push(x + y);
    } else if (e == "-") {
      int x = s.top();
      s.pop();
      int y = s.top();
      s.pop();
      s.push(y - x);
    } else if (e == "*") {
      int x = s.top();
      s.pop();
      int y = s.top();
      s.pop();
      s.push(x * y);
    } else if (e == "/") {
      int x = s.top();
      s.pop();
      int y = s.top();
      s.pop();
      s.push(y / x);
    } else {
      s.push(stoi(e));
    }
    i++;
  }
  return s.top();
}

int32_t main() {
  clock_t _t = clock();

  /* vector<string> tokens = {"2", "1", "+", "3", "*"}; */
  /* vector<string> tokens = {"4", "13", "5", "/", "+"}; */
  vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                           "/",  "*", "17", "+", "5", "+"};
  std::cout << evalRPN(tokens) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
