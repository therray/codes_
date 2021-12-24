// author: erray
#include <bits/stdc++.h>
 
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>>
struct SparseTable {
  vector<vector<T>> a;
  vector<int> logs;
  int n;
  F op;
  SparseTable() { }
  SparseTable(vector<T> _a, F _op) : op(_op) {
    n = int(_a.size());
    int lg = 32 - __builtin_clz(n);
    a.resize(lg);
    a[0] = _a;
    for (int j = 1; j < lg; ++j) {
      int size = n - (1 << j) + 1;
      a[j].resize(size);
      for (int i = 0; i < size; ++i) {
        a[j][i] = op(a[j - 1][i], a[j - 1][i + ((1 << (j - 1)))]);
      }
    }
    logs.resize(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      logs[i] = logs[(i >> 1)] + 1;
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int lg = logs[r - l + 1];;
    return op(a[lg][l], a[lg][r + 1 - (1 << lg)]);
  }
};

struct EulerTourLCA {
  int n;
  vector<int> d, tin, tout;
  SparseTable<int> st;
  EulerTourLCA(vector<vector<int>> g, int root = 0) {
    n = int(g.size());
    vector<int> tour;
    d.resize(n);
    tin.resize(n);
    tout.resize(n);
    function<void(int, int)> Dfs = [&](int v, int pr) {
      tin[v] = tout[v] = int(tour.size());
      tour.push_back(v);
      for (auto u : g[v]) {
        if (u == pr) {
          continue;
        }
        d[u] = d[v] + 1;
        Dfs(u, v);
        tout[v] = int(tour.size());
        tour.push_back(v);
      }
    };
    if (root == -1) {
      for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
          Dfs(i, -1);
        }
      }
    } else {
      Dfs(root, -1);
    }
    st = SparseTable<int>(tour, [&](int x, int y) {
      return (d[x] < d[y] ? x : y);
    });
  }

  int is_ancestor(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
  }

  int lca(int v, int u) {
    assert(v >= 0 && u >= 0 && v < n && u < n);
    if (tin[v] > tin[u]) {
      swap(v, u);
    }
    return (is_ancestor(v, u) ? v : st.get(tout[v], tin[u]));
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> size(n, 1);
  function<void(int, int)> Pre = [&](int v, int pr) {
    for (auto u : g[v]) {
      if (u != pr) {
        Pre(u, v);
        size[v] += size[u];
      }
    }
  };
  Pre(0, -1);
  int root = 0;
  int next = 0;
  int prev = 0;
  while (next != -1) {
    prev = root;
    root = next;
    next = -1;
    for (auto u : g[root]) {
      if (u != prev && size[u] * 2 >= n) {
        next = u;
        size[root] -= size[u];
        size[u] += size[root];
      }
    }
  }

  vector<int> d(n);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    for (auto u : g[v]) {
      if (u != pr) {
        d[u] = d[v] + 1;
        Dfs(u, v);
      }
    }
  };
  Dfs(root, -1);
  EulerTourLCA et(g, root);
  auto Dist = [&](int x, int y) {
    return d[x] + d[y] - 2 * d[et.lca(x, y)];
  };

  vector<vector<int>> all(n + 1);
  vector<int> ans(n / 2 + 1);
  for (int i = 0; i < n; ++i) {
    all[size[i]].push_back(i);
  }

  int v1 = root, v2 = root;
  for (int i = n / 2; i >= 1; --i) {
    for (auto v : all[i]) {
      int v3 = v;
      if (Dist(v1, v2) < Dist(v2, v3)) {
        swap(v1, v3);
      } else if (Dist(v1, v2) < Dist(v1, v3)) {
        swap(v2, v3);
      }  
    }
    ans[i] = Dist(v1, v2);
  }

  for (int i = 1; i <= n; ++i) {
    cout << (i % 2 ? 1 : ans[i / 2] + 1) << '\n';
  }
}