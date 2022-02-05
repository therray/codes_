// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

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
  int TT;
  cin >> TT;
  while (TT--) {
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

    EulerTourLCA et(g, 0);
    vector<int> d(N);
    function<void(int)> Dfs = [&](int v) {
      for (auto u : g[v]) {
        g[u].erase(find(g[u].begin(), g[u].end(), v));
        d[u] = d[v] + 1;
        Dfs(u);
      }
    };
    Dfs(0);
    vector<vector<int>> gs(N);
    for (int i = 0; i < N; ++i) {
      gs[d[i]].push_back(i);   
    }
    int mx = *max_element(d.begin(), d.end());
    vector<int> till(N, mx);
    int l = int(max_element(d.begin(), d.end()) - d.begin());
    for (int i = mx - 1; i >= 0; --i) {
      for (auto v : gs[i + 1]) {
        l = et.lca(l, v);
      }     
      int need = mx - i;
      int res = d[l] - need;
      if (res <= 0) {
        break;
      }
      till[res - 1] = i;
    }

    for (int i = N - 2; i >= 0; --i) {
      till[i] = min(till[i], till[i + 1]);
    }
    for (auto e : till) {
      cout << e << ' ';
    }
    //debug(till);
    cout << '\n';
  }
}