// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

template<typename F = function<void(int, int)>> struct HLD {
  int n;
  vector<int> d;
  vector<int> root;
  vector<int> ind;
  vector<int> par;
  vector<vector<int>> g;
  HLD(int _n) : n(_n) {
    d.resize(n);
    root.resize(n);
    g.resize(n);
    ind.resize(n);
    par.resize(n, -1);
  }
  
  void add_edge(int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int dfs(int v) {
    int res = 1;
    int mx = -1;
    for (int i = 0; i < int(g[v].size()); ++i) {
      int u = g[v][i];
      if (u == par[v]) {
        continue;
      }
      d[u] = d[v] + 1;
      par[u] = v;
      int s = dfs(u);
      res += s;
      if (mx < s) {
        swap(g[v][0], g[v][i]);    
        mx = s;
      }
    }
    return res;
  }

  int t = 0;
  void index(int v) {
    ind[v] = t++;
    for (int i = 0; i < int(g[v].size()); ++i) {
      int u = g[v][i];
      if (u != par[v]) {
        root[u] = (i == 0 ? root[v] : u);
        index(u);  
      }
    }
  }
                                              
  void build() {
    dfs(0);
    index(0); 
  }

  void path(int v, int u, F op, bool edge = true) {
    int tot = 0;
    while (root[v] != root[u]) {
      debug(v, u);
      if (d[root[v]] < d[root[u]]) {
        swap(u, v);
      }
      tot += 1;
      op(ind[root[v]], ind[v]);
      v = par[root[v]]; 
    }
    debug(tot + 1);
    if (ind[v] > ind[u]) {
      swap(u, v);
    }
    if (edge) {
      if (ind[v] != ind[u]) {
        op(ind[v] + 1, ind[u]);
      }
    } else {
      op(ind[v], ind[u]);      
    }
  }
};

const int inf = int(1e9);
struct SegTree {
  int n;
  vector<int> tree;
  SegTree(int _n) : n(_n) {
    tree.resize((n << 1), -inf);
  }
  int get(int l, int r) {
    assert(l >= 0 && l <= r && r < n);
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
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
  void modify(int x, int y) {
    assert(x >= 0 && x < n);
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
    HLD<function<void(int, int)>> hld(N);
    vector<array<int, 3>> E(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      cin >> E[i][0] >> E[i][1] >> E[i][2];
      --E[i][0], --E[i][1];
      hld.add_edge(E[i][0], E[i][1]);
    }
    hld.build();
    debug("BUILT");
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
    int it = 0;
    while (Q != "DONE") {
      debug(++it);
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
  debug(clock());
}