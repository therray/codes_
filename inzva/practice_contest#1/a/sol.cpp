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
  for (int i = 0; i < N; ++i) {
    int M;
    cin >> M;
    for (int j = 0; j < M; ++j) {
      int X;
      cin >> X;
      g[X - 1].push_back(i);
    }
  }

  vector<bool> vis(N, false);
  vis[0] = true;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto u : g[v]) {
      if (!vis[u]) {
        vis[u] = true;
        que.push(u);
      }  
    }
  }

  cout << int(accumulate(vis.begin(), vis.end(), 0)) << '\n';
}