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
  int N;
  cin >> N;
  int ans = 0;
  vector<vector<int>> g(N);
  while (!cin.eof()) {
    int X, Y;
    cin >> X >> Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
    ans += 1;
  }

  vector<int> d(N);
  vector<int> back(N);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    for (auto u : g[v]) {
      if (u != pr) {
        if (d[u] == -1) {
          d[u] = d[v] + 1;
          Dfs(u, v);
          if (back[u] == 0) {
            ans -= 1;
          }
        } else {
          back[v] += (d[u] < d[v] ? 1 : -1);
        }
      }
    }
  };
  Dfs(0, -1);
  cout << ans << '\n';
}