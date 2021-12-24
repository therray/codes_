// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

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

    vector<int> c(N);
    function<void(int, int)> Dfs = [&](int v, int pr) {
      for (auto u : g[v]) {
        if (u != pr) {
          c[u] = c[v] ^ 1;
          Dfs(u, v);
        }
      }
    };
    Dfs(0, -1);
    
  }
}