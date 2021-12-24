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
  return rng() % (r - l + 1) + l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N = Rand(1, 100);
  int M = Rand(1, 100);
  int D = Rand(1, 100);
  cout << N << ' ' << M << ' ' << D << '\n';
  cout << 0 << ' ';
  for (int i = 0; i < M; ++i) {
    cout << Rand(1, 120) << ' ';
  }

  cout << '\n';
  for (int i = 0; i < M; ++i) {
    cout << Rand(0, 1) << ' ';
  }
}