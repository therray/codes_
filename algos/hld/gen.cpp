// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << 1 << '\n';
  int M = int(1e3);
  int N = rng() % M;
  cout << N << '\n';
  for (int i = 0; i < N - 1; ++i) {
    cout << rng() % (i + 1) + 1 << ' ' << i + 2 << ' ' << rng() % int(1e9) << '\n';
  }
  for (int it = 0; it < N; ++it) {
    int T = rng() % 2;
    if (T == 1) {
      cout << "QUERY " << rng() % N + 1 << ' ' << rng() % N + 1 << '\n';
    } else {
      cout << "CHANGE " << rng() % (N - 1) + 1 << ' ' << rng() % int(1e9) << '\n';
    }

  }
  cout << "DONE";
}