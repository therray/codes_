// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
  int size(int v) {
    return sz[get(v)];
  }
  bool same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  DSU d(N);
  vector<vector<int>> g(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    char C;
    cin >> X >> C >> Y;
    --X, --Y;
    if (C == 'h') {
      d.unite(X, Y);
    } else {
      g[X].push_back(Y);
      g[Y].push_back(X);
    }
  }  


  array<int, 2> ct = {};
  vector<int> c(N, -1);
  function<void(int)> Dfs = [&](int v) {
    ct[c[v]] += d.size(v);
    for (auto u : g[v]) {
      u = d.get(u);
      if (c[u] == -1) {
        c[u] = c[v] ^ 1;
        Dfs(u);
      } 
      //assert(c[u] != c[v]); WTF
    }  
  };

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int v = d.get(i);
    if (c[v] == -1) {
      c[v] = 0;
      ct = {};
      Dfs(v);
      ans += max(ct[0], ct[1]);
    }
  }
  cout << ans << '\n';

}