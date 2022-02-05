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
  int N = 10;
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    S[i].resize(i + 1);
    for (int j = 0; j <= i; ++j) {
      S[i][j] = 'a' + (rng() % 8);
    }
    cout << '"' << S[i] << '"' << '\n';
  }

  cout << '\n';
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int res = 0;
    for (int j = 0; j <= i; ++j) {
      res += (j + 1) * (S[i][j] - 'a' + 1);
    }
    cout << '"' << S[i] << '"' << ": " << res << '\n';
    ans += res;
  }
  cout << ans << '\n';
}