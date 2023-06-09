#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node *links[26];

  bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }

  Node *get(char ch) { return links[ch - 'a']; }

  void put(char ch, Node *node) { links[ch - 'a'] = node; }
};

/*You are required to complete this method */
int countDistinctSubstring(string s) {
  // Your code here
  Node *root = new Node();
  int count = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    Node *node = root;

    for (int j = i; j < n; j++) {
      if (!node->containsKey(s[j])) {
        node->put(s[j], new Node());
        count++;
      }
      node = node->get(s[j]);
    }
  }
  return count + 1;
}

int32_t main() {
  clock_t _t = clock();

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
