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

    for (int i = 1; i <= N; ++i) {
      int ans = N + 1;
      for (int f = 0; f < N; ++f) {
        for (int s = 0; s < N; ++s) {
          vector<vector<int>> que(N);
          vector<int> dist(N, -1);
          que[0].push_back(0);
          dist[0] = 0;
          for (int d = 0; d < N; ++d) {
            for (auto v : que[d]) {
              if (dist[v] < d) {
                continue;
              }
              if (f == v || s == v) {
                int to = s ^ f ^ v;
                if (dist[to] == -1) {
                  dist[to] = d + i;
                  if (dist[to] < N) {
                    que[dist[to]].push_back(to);
                  } 
                }
              }
              for (auto u : g[v]) {
                if (dist[u] == -1 || dist[u] > d + 1) {
                  dist[u] = d + 1;
                  que[d + 1].push_back(u);
                }
              }
            }
          }
          ans = min(ans, *max_element(dist.begin(), dist.end()));
        }
      }
      cout << ans << ' ';    
    }
    cout << '\n';
  }
}