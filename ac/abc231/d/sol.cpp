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
  bool ok = true;
  vector<int> deg(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    ok &= (deg[X] <= 1 && deg[Y] <= 1);
    deg[X] += 1;
    deg[Y] += 1;
    ok &= d.unite(X, Y);
  }
  cout << (ok ? "Yes" : "No") << '\n';
}