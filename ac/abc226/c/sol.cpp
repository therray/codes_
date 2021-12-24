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
  int N;
  cin >> N;
  vector<vector<int>> g(N);
  vector<int> T(N);
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
    int K;
    cin >> K;
    g[i].resize(K);
    for (int j = 0; j < K; ++j) {
      cin >> g[i][j];
      --g[i][j];
    }
  }

  queue<int> que;
  vector<bool> vis(N);
  vis[N - 1] = true;
  que.push(N - 1);
  long long ans = 0;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    ans += T[v];
    for (auto u : g[v]) {
      if (!vis[u]) {
        vis[u] = true;
        que.push(u);  
      }
    }
  }
  cout << ans << '\n';
}
