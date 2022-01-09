#undef DEBUG
// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

template<bool EDGE = false>
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

  template<typename F> void path(int v, int u, F op) {
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

const int inf = int(1e9);
struct SegTree {
  int n;
  vector<int> tree;
  SegTree(int _n) : n(_n) {
    tree.resize((n << 1), -inf);
  }
  int get(int l, int r) {
    l += n;
    r += n + 1;
    int res = -inf;
    while (l < r) {
      if (l & 1) {
        res = max(res, tree[l]);
        l += 1;
      }
      if (r & 1) {
        r -= 1;
        res = max(res, tree[r]);
      }
    }
    return res;
  }
  void modify(int x, int y) {
    x += n;
    tree[x] = y;
    while (x > 1) {
      tree[x >> 1] = max(tree[x], tree[x ^ 1]);
      x >>= 1;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    HLD<true, function<void(int, int)>> hld(N);
    vector<array<int, 3>> E(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      cin >> E[i][0] >> E[i][1] >> E[i][2];
      --E[i][0], --E[i][1];
      hld.add_edge(E[i][0], E[i][1]);
    }
    hld.build();
    SegTree st(N);
    auto Modify = [&](int i) {
      hld.path(E[i][0], E[i][1], [&](int l, int r) {
        assert(l == r);
        st.modify(l, E[i][2]);
      });
    };
    for (int i = 0; i < N - 1; ++i) {
      Modify(i);
    }
    string Q;
    cin >> Q;
    while (Q != "DONE") {
      if (Q == "CHANGE") {
        int ID, X;
        cin >> ID >> X;
        --ID;
        E[ID][2] = X;
        Modify(ID); 
      } else {
        int X, Y;
        cin >> X >> Y;
        --X, --Y;
        int res = -inf;
        hld.path(X, Y, [&](int l, int r) {
          res = max(res, st.get(l, r));
        });
        cout << res << '\n'; 
      }     
      cin >> Q;
    }

  }
}