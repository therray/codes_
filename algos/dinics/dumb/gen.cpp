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

int Rand(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N = Rand(5, 6);
  int M = Rand(5, 6);
  int P = Rand(1, N * M / 2);
  cout << N << ' ' << M << ' ' << P << '\n';
  for (int i = 0; i < P; ++i) {
    cout << Rand(1, N) << ' ' << Rand(1, M) << '\n';
  }
}