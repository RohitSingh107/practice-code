/* https://practice.geeksforgeeks.org/problems/bipartite-graph/1 */
#include <iterator>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool dfs(int V, int c, vector<int> adj[], vector<int> &colors) {
  std::cout << "Entered " << V << "color is " << colors[V] << std::endl;

  if (colors[V] != -1) {
    std::cout << "here return"
              << " color is " << colors[V] << std::endl;
    return colors[V] == c;
  }

  std::cout << "here2" << std::endl;

  bool ans = true;

  colors[V] = c;

  for (auto v : adj[V]) {
    ans = ans && dfs(v, !c, adj, colors);
  }

  return ans;
}

bool isBipartite(int V, vector<int> adj[]) {

  /* int n = *(adj->end() - adj->front()); */
  /* std::cout << "size is " << n << std::endl; */

  vector<int> colors(100005, -1);

  std::cout << "out color is " << colors[V] << std::endl;
  return dfs(V, -1, adj, colors);
}

int32_t main() {
  clock_t _t = clock();

  /* vector<int> adj[] = {{2, 3}, {3}, {0, 3}, {0, 1, 2}}; */
  vector<int> adj[] = {{1}, {0, 2}, {1, 3}, {2}};

  /* std::cout << !(-1) << std::endl; */

  std::cout << isBipartite(3, adj) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
