// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  cout << N << '\n';
  vector<vector<int>> g(N);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if ((rng() % 3) == 0) {
        g[i].push_back(j);
        g[j].push_back(i);
        cout << i << ' ' << j << '\n';
      }
    }
  }
}