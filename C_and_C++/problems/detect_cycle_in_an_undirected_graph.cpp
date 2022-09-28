#include <queue>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool bfs(int source, int parent, vector<int> adj[], vector<bool> &visited) {

  visited[source] = true;
  queue<pair<int, int>> q;
  q.push({source, parent});

  while (!q.empty()) {
    auto fr = q.front();
    q.pop();
    int v = fr.first;
    int p = fr.second;

    for (auto i : adj[v]) {

      if (visited[i] && i != p) {
        return true;
      }

      if (!visited[i]) {
        q.push({i, v});
        visited[i] = true;
      }
    }
  }
  return false;
}

bool dfs(int source, int parent, vector<int> adj[], vector<bool> &visited) {

  visited[source] = true;

  int ans = false;

  for (auto i : adj[source]) {

    if (visited[i] && i != parent) {
      return true;
    }

    if (!visited[i]) {
      ans |= dfs(i, source, adj, visited);
    }
  }
  return ans;
}

bool isCycle(int V, vector<int> adj[]) {

  vector<bool> visited(V + 1, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      if (dfs(i, -1, adj, visited)) {
        return true;
      }
    }
  }

  return false;
}

int32_t main() {
  clock_t _t = clock();

  /* int V = 5; */
  /* vector<int> adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}; */

  int V = 4;
  vector<int> adj[] = {{}, {2}, {1, 3}, {2}};

  std::cout << isCycle(V, adj) << std::endl;

  cerr << "Run Time: " << (double)(clock() - _t) / CLOCKS_PER_SEC << " seconds";
  return 0;
}
