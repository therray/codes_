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
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  vector<vector<int>> g(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }

  using T = pair<long long, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  const long long inf = (long long) 1e17;
  vector<long long> cost(N, inf);
  auto Add = [&](int x, long long c) {
    if (c < cost[x]) {
      cost[x] = c;
      pq.emplace(cost[x] - H[x], x);
    }
  };

  vector<bool> vis(N);
  Add(0, 0);
  while (!pq.empty()) {
    auto[ignore, v] = pq.top();
    pq.pop();
    if (vis[v]) {
      continue;
    }
    vis[v] = true;
    for (auto u : g[v]) {
      int diff = H[u] - H[v];
      if (diff > 0) {
        diff *= 2;
      }
      Add(u, cost[v] + diff);
    }
  }
  cout << -*(min_element(cost.begin(), cost.end())) << '\n';
}