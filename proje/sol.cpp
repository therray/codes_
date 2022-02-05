// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N >> M;
  cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }

  vector<int> d(N, -1);
  vector<int> e(N);
  long long ans = 0;
  int bridge = 0;
  int one = 0;
  vector<bool> dis(N);
  vector<int> ord;
  vector<int> last(N);
  function<void(int)> Dfs = [&](int v) {
    ord.push_back(v);
    for (auto u : g[v]) {
      g[u].erase(find(g[u].begin(), g[u].end(), v));
      if (d[u] == -1) {
        d[u] = d[v] + 1;
        Dfs(u);
      } else {
        e[v] += (d[u] < d[v] ? 1 : -1);
        last[v] = v;
      }
    }
    if (e[v] == 0) {
      last[v] = v;
    }
  };
  Dfs(0);
  //back to back
  ans += 1LL * (M - N + 1) * (M - N) / 2;
  //tree to back
  ans += 1LL * (N - 1 - bridge) * back - one;
  //tree to tree
  ans += 1LL * (N - 1 - bridge) * (N - 2 - bridge) / 2;	
  for (auto v : ord) {
    for (auto u : g[v]) {
      if (d[u] == d[v] + 1) {
        if (last[u] == -1) {
          last[u] = last[v];
        }
      }
    }
  }
  cout << ans << '\n';
}