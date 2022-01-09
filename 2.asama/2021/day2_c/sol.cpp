//author: erray
#include <bits/stdc++.h>

using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>>
struct SparseTable {
  vector<vector<T>> table;
  int n;
  F op;
  SparseTable(vector<T> x, F _op) : op(_op) {
    n = int(x.size());
    int lg = __lg(n) + 1;
    table.resize(lg);
    table[0] = x;
    for (int j = 1; j < lg; ++j) {
      table[j].resize(n - (1 << j) + 1);
      for (int i = 0; i < n - (1 << j) + 1; ++i) {
        table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && l <= r && r < n);
    int lg = __lg(r - l + 1);
    return op(table[lg][l], table[lg][r + 1 - (1 << lg)]);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int Q;
  cin >> Q;
  vector<vector<int>> g(Q + 1);
  vector<int> QS(Q);
  vector<int> from(Q + 1);
  int tt = 0;
  for (int i = 0; i < Q; ++i) {
    cin >> QS[i];
    if (QS[i] == 1) {
      cin >> QS[i];
      --QS[i];
      ++tt;
      g[QS[i]].push_back(tt);      
      g[tt].push_back(QS[i]);
      from[tt] = QS[i];
    } else {
      QS[i] -= 4;
    }
  }
  
  int N = int(g.size());
  vector<int> tour;
  vector<int> d(N);
  vector<int> tin(N);
  vector<int> tout(N);
  const int LG = __lg(N) + 1;
  vector<vector<int>> lift(LG, vector<int>(N));  
  function<void(int, int)> Dfs = [&](int v, int pr) {
    lift[0][v] = (pr == -1 ? 0 : pr);
    tin[v] = tout[v] = int(tour.size());
    tour.push_back(v);
    for (auto u : g[v]) {
      if (u != pr) {
        d[u] = d[v] + 1;
        Dfs(u, v);
        tout[v] = int(tour.size());
        tour.push_back(v);
      }
    }
  };
  Dfs(0, -1);
 
  for (int j = 1; j < LG; ++j) {
    for (int i = 0; i < N; ++i) {
      lift[j][i] = lift[j - 1][lift[j - 1][i]];
    }
  }
  SparseTable<int> LCA(tour, [&](int x, int y) {
    return (d[x] < d[y] ? x : y);
  });
  auto lca = [&](int v, int u) {
    if (tin[v] > tin[u]) {
      swap(v, u);
    }
    if (tout[v] >= tout[u]) {
      return v;
    }
    return LCA.get(tout[v], tin[u]);
  };
  auto dist = [&](int v, int u) {
    return d[v] + d[u] - 2 * d[lca(v, u)];
  };
  auto go = [&](int v, int u, int p){
    assert(p < dist(v, u));
    int l = lca(v, u);
    int f = -1;
    if (dist(l, v) >= p) {
      f = v;
    } else {
      p = dist(v, u) - p;
      f = u;
    }
    for (int j = LG - 1; j >= 0; --j) {
      if (p & (1 << j)) {
        f = lift[j][f];
      }
    }
    return f;
  };

  int v = 0, u = 0;
  int lv = 0, lu = 0;
  auto Add = [&](int x) {
    int dia = dist(v, u);
    if (dist(v, x) < dia && dist(u, x) < dia) {
      return;
    }
    if (dist(v, x) > dia) {
      lu = u = x;
    } else if (dist(x, u) > dia) {
      lv = v = x;
    } else {
      if (dist(v, x) == dia) {
        int ff = dist(u, x);
        assert(ff % 2 == 0);
        if (dist(u, lu) < ff / 2) {
          lu = go(u, x, ff / 2);
        }
      } 
      if(dist(u, x) == dia) {
        int ff = dist(v, x);
        assert(ff % 2 == 0);
        if (dist(v, lv) < ff / 2) {
          lv = go(v, x, ff / 2);
        }
      }
    }
  };
  
  int t = 1;
  for (auto e : QS) {
    if (e >= 0) {
      Add(t++);
    } else {
      if (e == -2) {
        cout << dist(v, u) + 1 << '\n';
      } else {
        cout << (dist(lv, lu) + 1) << '\n'; 
      }  
    }
  }
  
}