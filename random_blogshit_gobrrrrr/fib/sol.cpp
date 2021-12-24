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
  vector<int> fib(2, 1);
  while (fib.back() <= 108) {
    fib.push_back(fib.back() + fib[int(fib.size()) - 2]);
  }
  fib.pop_back();

  const int inf = N;
  vector<int> dp(N + 1, inf);
  vector<vector<vector<int>>> way(N + 1);
  way[0].push_back({});
  dp[0] = 0;
  for (int i = 0; i <= N; ++i) {
    for (auto e : fib) {
      int x = i + e;
      if (x <= N && dp[i] + 1 <= dp[x]) {
        if (dp[x] > dp[i] + 1) {
          way[x].clear();
        }
        dp[x] = dp[i] + 1;
        for (auto p : way[i]) {
          p.push_back(e);
          way[x].push_back(p);
        }
      }
    }
  }

  for (auto& e : way[N]) {
    sort(e.begin(), e.end());
  }
  sort(way[N].begin(), way[N].end());
  way[N].resize(int(unique(way[N].begin(), way[N].end()) - way[N].begin()));
  for (auto e : way[N]) {
    for (auto ee : e) {
      cout << ee << ' ';
    }
    cout << endl;
  }
}