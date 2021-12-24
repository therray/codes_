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
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return B[x] < B[y];
  });

  vector<vector<pair<int, int>>> g(N * 2);
  for (int i = 0; i < N - 1; ++i) {
    int x = ord[i];
    int y = ord[i + 1];
    assert(B[y] >= B[x]);
    g[N + x].emplace_back(N + y, B[y] - B[x]);
  }
  for (int i = 0; i < N; ++i) {
    g[N + i].emplace_back(i, 0);
  }

  for (int i = 0; i < N; ++i) {
    int low = 0, high = N - 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (A[i] + B[ord[mid]] < M) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    
    for (auto add : {0, low}) {
      g[i].emplace_back(N + ord[add], (A[i] + B[ord[add]]) % M);  
    } 
  }
  debug(g);

  const long long inf = (long long) 1e15;
  vector<long long> dist(N * 2, inf);
  {
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    while (!pq.empty()) {
      auto[cost, v] = pq.top();
      pq.pop();
      if (dist[v] < cost) {
        continue;
      }
      for (auto[u, c] : g[v]) {
        if (dist[u] > cost + c) {
          dist[u] = cost + c;
          pq.emplace(dist[u], u);
        } 
      }
    }
  }

  cout << dist[N - 1] << '\n';
}