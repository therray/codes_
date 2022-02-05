// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<bool EDGE = false, class F = function<void(int, int)>>
struct HLD {
  int n;
  vector<vector<int>> g;
  vector<int> d, root, par, ind, end;
  HLD() { }
  HLD(int _n) : n(_n) {
    g.resize(n);
    d.resize(n);
    root.resize(n);
    iota(root.begin(), root.end(), 0);
    ind.resize(n);
    par.resize(n, -1);
    end.resize(n);
  }

  void add_edge(int v, int u) {
    assert(v >= 0 && u >= 0 && v < n && u < n);
    g[v].push_back(u);
    g[u].push_back(v);
  }

  void add_edge(vector<vector<int>> _g) {
    for (int i = 0; i < n; ++i) {
      for (auto u : g[i]) {
        add_edge(i, u);
      }
    }
  }

  int dfs(int v) {
    int size = 0;
    int mx = -1;
    for (int i = 0; i < int(g[v].size()); ++i) {
      int u = g[v][i];
      if (u == par[v]) {
        continue;
      }
      d[u] = d[v] + 1;
      par[u] = v;
      int sz = dfs(u);
      size += sz;
      if (sz > mx) {
        swap(g[v][0], g[v][i]);
        mx = sz;
      }
    }
    return size;
  }

  void index(int v, int& t) {
    end[v] = ind[v] = t++;
    bool heavy = true;
    for (auto u : g[v]) {
      if (u == par[v]) {
        continue;
      }
      if (heavy) {
        root[u] = root[v];
        heavy = false;
      }
      index(u, t);
    }
    end[v] = t;
  }

  bool built = false;
  void build() {
    built = true;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (par[i] == -1) {
        dfs(i);
        index(i, t);
      }
    }
  }

  void path(int v, int u, F op) {
    assert(built);
    if (u == -1) {
      u = (EDGE ? par[v] : v);
    }
    assert(v >= 0 && u >= 0 && v < n && u < n);
    while (root[v] != root[u]) {
      if (d[root[v]] < d[root[u]]) {
        swap(v, u);
      }
      op(ind[root[v]], ind[v]);
      v = par[root[v]];
    }
    if (d[v] > d[u]) {
      swap(v, u);
    }
    if (EDGE) {
      if (v != u) {
        op(ind[v] + 1, ind[u]);
      }
    } else {
      op(ind[v], ind[u]);
    }
  }

  void subtree(int v, F op) {
    if (!EDGE) {
      op(ind[v], end[v]);
    } else {
      if (ind[v] != end[v]) {
        op(ind[v] + 1, end[v]);
      }
    }
  }
};
//container should be declared and used apart from HLD struct

struct SegTree {
  int n;
  vector<node> tree;
  void modify(int v, int int l, int r, int ll, int rr, 
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
}