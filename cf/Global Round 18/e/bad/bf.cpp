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
  int N, K;
  cin >> N >> K;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[Y].push_back(X);
    g[X].push_back(Y);
  }
  
  function<void(int)> Dfs = [&](int v) {
    for (auto u : g[v]) {
      g[u].erase(find(g[u].begin(), g[u].end(), v));
      Dfs(u);
    }
  };
  Dfs(0);

  debug(g);
  long long ans = LLONG_MIN;
  for (int mask = 0; mask < (1 << N); ++mask) {
    vector<int> c(N);
    for (int i = 0; i < N; ++i) {
      c[i] |= ((mask >> i) & 1);
      for (auto u : g[i]) {
        c[u] |= c[i];
      }
    }

    int r = accumulate(c.begin(), c.end(), 0);
    if (r > K) {
      continue;
    }

    vector<int> sum(N);
    int b = 0;
    for (int i = N - 1; i >= 0; --i) {
      sum[i] = c[i];
      for (auto u : g[i]) {
        sum[i] |= sum[u];
      }
      b += !sum[i];
    } 

    debug(mask, r, b);
    ans = max(ans, 1LL * (N - r - b) * (r - b));
  }
  cout << ans << '\n';
}