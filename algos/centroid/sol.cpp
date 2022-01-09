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
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  
  vector<vector<int>> cg(N);
  {
    vector<int> size(N, 1);
    function<void(int, int)> Pre = [&](int v, int pr) {
      for (auto u : g[v]) {
        if (u != pr) {
          Pre(u, v);
          size[v] += size[u];
        }
      }
    };
    
    Pre(0, -1);
    vector<bool> used(N);
    function<void(int, int)> Centroid = [&](int v, int pr) {
      int big = -1;
      for (auto u : g[v]) {
        if (size[u] * 2 > size[v]) {
          big = u;
        }
      }
      if (big == -1) {
        size[v] = 0;
        for (auto u : g[v]) {
          Centroid(u, v);
        }
        if (pr != -1) {
          cg[pr].push_back(v);
        }
      } else {
        size[v] -= size[big];
        size[big] += size[v];
        Centroid(big, pr);
      }   
    };
    Centroid(0, -1);
  }
  
}