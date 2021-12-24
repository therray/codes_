// author: erray
#include <bits/stdc++.h>
 
using namespace std;


struct dsu {
  vector<int> par, sz;
  dsu(int n) {
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
  int n, m;
  cin >> n >> m;
  vector<int> p(n + m);
  for (int i = 0; i < n + m; ++i) {
    cin >> p[i];
    --p[i];
  }

  dsu d(n + m);
  for (int i = 0; i < n + m; ++i) {
    d.unite(i, p[i]);
  }

  vector<vector<int>> all(n + m);
  for (int i = 0; i < n + m; ++i) {
    all[d.get(i)].push_back(i);
  }

  int ans = n + m;
  array<int, 2> full = {};
  for (int i = 0; i < n + m; ++i) {
    if (d.get(i) == i) {
      ans -= 1;
      if (p[i] != i) {
        if (all[i].back() < n) {
          full[0] += 1;
        } else if (all[i].front() >= n) {
          full[1] += 1;
        }
      }
    }   
  }
  cout << ans + max(full[0], full[1]) * 2 << '\n';
}