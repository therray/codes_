//author: erray
#include<bits/stdc++.h>

using namespace std;
      
struct DSU {
  vector<int> par;
  DSU(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }
  int get(int x) {
    return par[x] = (par[x] == x ? x : get(par[x]));
  }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    par[y] = x;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, P;
  cin >> N >> M >> P;
  if (N <= 5 && M <= 5) {

    exit(0);
  }
  vector<vector<int>> g(N);
  DSU d(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
    d.unite(X, Y);
  } 

  set<int> st;
  for (int i = 0; i < N; ++i) {
    for (auto u : g[i]) {
      st.insert(d.get(u)); 
    }
  }
  if (int(st.size()) > 1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  int p = 0;
  while (p < N && int(g[p].size()) != 1) {
    ++p;
  }

  if (p == N) {
    p = 0;
  while (p < N && int(g[p].size()) != 2) {
    ++p;
  }
    
  }
    int v = g[p][0];
    int pre = p;
    for (int i = 0; i < M - 1; ++i) {
      int next = g[v][0] ^ (int(g[v].size()) > 1 ? g[v][1] : pre) ^ pre;
      cout << p + 1 << ' ' << v + 1 << ' ' << next + 1 << '\n';
      pre = v;
      v = next;

  }
}   