#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, sz;
  int num_components;

  DSU(int n) {
    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n + 1, 1);
    num_components = n;
  }

  int find(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i]);
  }

  void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
      if (sz[root_i] < sz[root_j])
        swap(root_i, root_j);
      parent[root_j] = root_i;
      sz[root_i] += sz[root_j];
      num_components--;
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> bad_edges(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    bad_edges[u].push_back(v);
    bad_edges[v].push_back(u);
  }

  DSU dsu(n);
  set<int> roots;
  for (int i = 1; i <= n; i++)
    roots.insert(i);

  vector<int> current_roots;
  for (int i = 1; i <= n; i++) {
    if (roots.find(i) == roots.end())
      continue;
  }

  set<int> unvisited;
  for (int i = 1; i <= n; i++)
    unvisited.insert(i);

  int components = 0;
  while (!unvisited.empty()) {
    components++;
    int start = *unvisited.begin();
    unvisited.erase(unvisited.begin());

    vector<int> q = {start};
    int head = 0;
    while (head < q.size()) {
      int u = q[head++];

      set<int> weight1_neighbors;
      for (int v : bad_edges[u])
        weight1_neighbors.insert(v);

      for (auto it = unvisited.begin(); it != unvisited.end();) {
        int v = *it;
        if (weight1_neighbors.find(v) == weight1_neighbors.end()) {
          q.push_back(v);
          it = unvisited.erase(it);
        } else {
          it++;
        }
      }
    }
  }

  cout << components - 1 << endl;

  return 0;
}