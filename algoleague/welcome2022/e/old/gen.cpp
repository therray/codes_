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
  int N = rand() % 1 + 5;
  cout << N << '\n';
  for (int i = 0; i < N; ++i) {
    cout << uniform_int_distribution<int>(1, int(N))(rng) << ' ' << uniform_int_distribution<int>(1, int(N))(rng) << '\n';
  }
}